#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "json.hpp"
#include "errors.hpp"

using json = nlohmann::json;

class User
{
public:
    User(int id, std::string username, std::string password, bool isAdmin, std::string phoneNumber, std::string address, int money);
    ~User();
    std::string getName();
    std::string getPassword();
    int getFd();
    int getId();
    void setInfo(std::string &password, int id, std::string &phoneNumber, std::string &address, int money);
    json viewInfo(bool isSelfInfo);
    json editInformation(json command);
    bool isAdmin();
    void setFd(int fd);
    void logout();
    int getMoney();
    void pay(int payment);
    void getBackMoney(int money);
    std::string getPhoneNumber();
    std::string getAddress();
    bool getIsAdmin();

private:
    std::string username_;
    std::string password_;
    int id_;
    bool isAdmin_;
    std::string phoneNumber_;
    std::string address_;
    int money_;
    int fd_;
};

#endif
