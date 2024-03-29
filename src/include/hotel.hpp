#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "reservation.hpp"
#include "room.hpp"
#include "user.hpp"
#include <vector>
#include <unordered_map>
#include <fstream>

#define ROOMS_FILE "jsonFiles/RoomsInfo.json"
#define USERS_FILE "jsonFiles/UsersInfo.json"
// #define ROOM_NOT_FOUND "Error 101: The desired room was not found."
// #define RESERVE_NOT_FOUND "Error 102: Your reservation was not found."
// #define SUCCESSFULLY_ADDED "Error 104: Successfully added."
// #define SUCCESSFULLY_MODIFIED "Error 105: Successfully modified."
// #define SUCCESSFULLY_DELETED "Error 106: Successfully deleted."
// #define LOW_BALANCE "Error 108: Your account balance is not enough."
// #define ROOM_IS_FULL "Error 109: The room capacity is full."
// #define ROOM_EXIST "Error 111: This room already exists."
// #define USER_SUCCESSFULLY_SIGN_UP "Error 231: User successfully signed up."
// #define ACCESS_DENIED "Error 403: Access Denied."
// #define INVALID_CAPACITY "Error 412: Invalid capacity value!"
// #define SUCCESSFULLY_LEAVING "Error 413: Successfully leaving."

class Hotel
{
public:
    Hotel();
    ~Hotel();
    void addRoom(int roomNo, int maxCapacity, int freeCapacity, int price, bool isFull);
    void addReservation(int roomNo, int userId, std::string &reserveDate, std::string &checkOutDate, int numOfBeds);
    // bool isDateValid(std::string& date);
    User *findUser(int userFd);
    json findUserByName(std::string username, std::string password, int userFd);
    json addUser(json command);
    json viewAllUsers(User *user);
    json viewRooms(bool isUserAdmin, bool isEmptyRoom);
    json editRooms(bool isUserAdmin);
    json addNewRoom(json command);
    json modifyRoom(json command);
    json removeRoom(json command);
    json leavingRoom(User *user, int value);
    json emptyRoom(int roomNo, bool isUserAdmin);
    void addRooms(json &rooms);
    void addUsers(json &users);
    void setDate(date::year_month_day date);
    void setUserFd(User *user, int userFd);
    json checkUsernameExistance(std::string username);
    Room *doesRoomExist(int roomNo);
    json logoutUser(User *user);
    json passDay(int daysNo, bool isUserAdmin);
    date::year_month_day convertDate(std::string date);
    json booking(User *user, json command);
    bool doesHaveTimeConflict(date::year_month_day reserveDate1, date::year_month_day checkOutDate1,
                              date::year_month_day reserveDate2, date::year_month_day checkOutDate2);
    json showUserReserves(User *user);
    json canceling(User *user, json command);
    void updateRoomsFile();
    void updateUsersFile();
    date::year_month_day findLastCheckOut(int roomNo);

private:
    std::unordered_map<int, User> users_;
    std::unordered_map<int, std::vector<Reservation>> reservations_;
    std::unordered_map<int, Room> rooms_;
    date::year_month_day date_;
    int lastAssignedId_;
};
#endif