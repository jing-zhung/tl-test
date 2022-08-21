#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.hpp"

const std::vector<std::string> ROOM_STATES = {"Available", "Occupied", "Vacant", "Repair"};

class Room
{
    public:
        std::string name_;
        std::string state_;
        Room(std::string name, std::string state)
        {
            this->name_ = name;
            this->state_ = state;
        };
};

class Hotel
{
    private:
        std::vector<std::string> room_states_;
        std::vector<Room*> rooms_;
        Graph* state_graph_;

        int getIndex(std::string state);
        bool setState(std::string room_name, int source_index, int destination_index);
    public:
        Hotel();
        ~Hotel();
        void addRooms(std::vector<std::pair<std::string, int>> rooms);
        void addRoom(Room* room);
        void addStateChange(std::string source_state, std::string destination_state);

        void printStateGraph();
        std::string assignRoom();
        bool checkOut(std::string room_name);
        bool setAvailable(std::string room_name);
        bool setRepair(std::string room_name);
        bool setVacant(std::string room_name);
        std::vector<std::string> listAvailableRooms();

        void deleteRooms();
};

#endif