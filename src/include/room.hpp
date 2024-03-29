#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

class Room
{
public:
    Room(int roomNo, int maxCapacity, int freeCapacity, int price, bool isFull);
    ~Room();
    int getRoomNo();
    int getMaxCapacity();
    int getFreeCapacity();
    // int getMaxUser();
    bool getIsFull();
    int getPrice();
    void setPrice(int price);
    void setFreeCapacity(int freeCapacity);
    void setMaxCapacity(int maxCapacity);
    void makeEmpty();
    void increaseSpace(int numOfGonePeople);
    void fill(int numOfBeds);
private:
    int roomNo_;
    int maxCapacity_;
    int price_;
    int freeCapacity_;
    bool isFull_;
};
#endif