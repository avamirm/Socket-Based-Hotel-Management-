#include "include/user.hpp"

User::User(int id, std::string username, std::string password, bool isAdmin, std::string phoneNumber, std::string address, int money)
{
    username_ = username;
    id_ = id;
    password_ = password;
    isAdmin_ = isAdmin;
    phoneNumber_ = phoneNumber;
    address_ = address;
    money_ = money;
    fd_ = -1;
}

User::~User()
{
}

void User::setInfo(std::string &password, int id, std::string &phoneNumber, std::string &address, int money)
{
    password_ = password;
    id_ = id;
    phoneNumber_ = phoneNumber;
    address_ = address;
    money_ = money;
}

std::string User::getName()
{
    return username_;
}

std::string User::getPassword()
{
    return password_;
}

int User::getFd()
{
    return fd_;
}

int User::getId()
{
    return id_;
}

json User::viewInfo(bool isSelfInfo)
{
    json info;
    info["username"] = username_;
    info["id"] = id_;
    info["isAdmin"] = isAdmin_;
    if (isSelfInfo)
        info["password"] = password_;
    if (!isAdmin_)
    {
        info["phoneNumber"] = phoneNumber_;
        info["address"] = address_;
        info["money"] = money_;
    }
    return info;
}

bool User::isAdmin()
{
    return isAdmin_;
}

json User::editInformation(json command)
{
    json response;
    if (isAdmin_)
    {
        password_ = command["newPassWord"];
    }
    else
    {
        password_ = command["newPassWord"];
        phoneNumber_ = command["newPhone"];
        address_ = command["newAddress"];
    }
    response["isError"] = false;
    response["errorMessage"] = INFORMATION_CHANGED;
    return response;
}

void User::setFd(int fd)
{
    fd_ = fd;
}

void User::logout()
{
    fd_ = -1;
}

int User::getMoney()
{
    return money_;
}

void User::pay(int payment)
{
    money_ -= payment;
}

void User::getBackMoney(int money)
{
    money_ += money/2;
}

std::string User::getPhoneNumber()
{
    return phoneNumber_;
}

std::string User::getAddress()
{
    return address_;
}

bool User::getIsAdmin()
{
    return isAdmin_;
}