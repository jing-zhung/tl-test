#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.hpp"

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
    public:
        Hotel(std::vector<std::string> room_states);
        ~Hotel();
        void addRooms(std::vector<std::pair<std::string, int>> rooms);
        void addRoom(Room* room);
        void addStateChange(std::string source_state, std::string destination_state);

        void printStateGraph();

        void deleteRooms();
};