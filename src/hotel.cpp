#include "hotel.hpp"

int Hotel::getIndex(std::string state)
{
    auto it = std::find(room_states_.begin(), room_states_.end(), state);

    // If element was found
    if (it != room_states_.end()) 
    {
        // calculating the index
        int index = it - room_states_.begin();
        return index;
    }
    else 
    {
        // If the element is not
        // present in the vector
        return -1;
    }
}

Hotel::Hotel(std::vector<std::string> room_states)
{
    this->room_states_ = room_states;
    state_graph_ = new Graph();
    for(auto room_state : room_states)
    {
        state_graph_->addVertex(new Vertex(room_state));
    }
}

Hotel::~Hotel()
{
    deleteRooms();
    state_graph_->deleteGraph();
}

void Hotel::addRooms(std::vector<std::pair<std::string, int>> rooms)
{
    for(auto room : rooms)
    {
        Room* current_room = new Room(room.first, room_states_[room.second]);
        addRoom(current_room);
    }
}

void Hotel::addRoom(Room* room)
{
    rooms_.push_back(room);
}

void Hotel::addStateChange(std::string source_state, std::string destination_state)
{
    int source_index = getIndex(source_state);
    int destination_index = getIndex(destination_state);

    state_graph_->addEdge(source_index, destination_index);
};

void Hotel::printStateGraph()
{
    state_graph_->printGraph();
}

std::string Hotel::assignRoom()
{
    return "";
}

bool Hotel::checkOut(std::string room_name)
{
    return true;
}

bool Hotel::setAvailable(std::string room_name)
{
    return true;
}

bool Hotel::setRepair(std::string room_name)
{
    return true;
}

std::vector<std::string> Hotel::listAvailableRooms()
{
    std::vector<std::string> available_rooms;
    for(auto room : rooms_)
    {
        if(room->state_ == room_states_[0])
        {
            available_rooms.push_back(room->name_);
        }
    }
    return available_rooms;
}

void Hotel::deleteRooms()
{
    for(auto room : rooms_)
    {
        delete room;
    }
}