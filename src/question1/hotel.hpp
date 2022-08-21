#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.hpp"

// Declare room states
const std::vector<std::string> ROOM_STATES = {"Available", "Occupied", "Vacant", "Repair"};

// Define room
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

//Define hotel
class Hotel
{
    private:
        std::vector<std::string> room_states_;
        std::vector<Room*> rooms_;
        Graph* state_graph_;

        /**
         * @brief Get index of a room state in the list of room states
         * @param state Name of room state
         * @return index of room state
         */
        int getIndex(std::string state);

        /**
         * @brief Set room state
         * @param room_name Name of room
         * @param source_index Index of source room state
         * @param destination_index Index of destination room state
         * @return boolean if successfully set room state or not
         */
        bool setState(std::string room_name, int source_index, int destination_index);

    public:
        Hotel();
        ~Hotel();

        /**
         * @brief Add rooms to hotel
         * @param rooms List of room names and their respective room states
         */
        void addRooms(std::vector<std::pair<std::string, int>> rooms);

        /**
         * @brief Add a room to hotel
         * @param room Room to be added
         */
        void addRoom(Room* room);

        /**
         * @brief Add a room state change link
         * @param source_state Name of source room state
         * @param destination_state Name of destination room state
         */
        void addStateChange(std::string source_state, std::string destination_state);

        /**
         * @brief Print graph of room states in terminal in the format of a list of adjacency lists
         */
        void printStateGraph();

        /**
         * @brief Assign an available room nearest to hotel entrance
         * @return name of room, or empty string if no available room
         */
        std::string assignRoom();

        /**
         * @brief Check out of room
         * @param room_name Name of room
         * @return boolean if successfully checked out of room or not
         */
        bool checkOut(std::string room_name);

        /**
         * @brief Set a vacant room to available
         * @param room_name Name of room
         * @return boolean if successfully set room state or not
         */
        bool setAvailable(std::string room_name);

        /**
         * @brief Set a vacant room to repair
         * @param room_name Name of room
         * @return boolean if successfully set room state or not
         */
        bool setRepair(std::string room_name);

        /**
         * @brief Set a room in repair to vacant
         * @param room_name Name of room
         * @return boolean if successfully set room state or not
         */
        bool setVacant(std::string room_name);

        /**
         * @brief List available rooms
         * @return lists or names of available rooms
         */
        std::vector<std::string> listAvailableRooms();

        /**
         * @brief Delete all rooms in hotel
         */
        void deleteRooms();
};

#endif