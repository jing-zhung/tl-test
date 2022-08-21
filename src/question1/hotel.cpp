#include "hotel.hpp"

Hotel::Hotel()
{
    this->room_states_ = ROOM_STATES;
    state_graph_ = new Graph();

    // Add room states as vertices in a graph
    for(auto room_state : ROOM_STATES)
    {
        state_graph_->addVertex(new Vertex(room_state));
    }

    this->addStateChange(ROOM_STATES[0], ROOM_STATES[1]);
    this->addStateChange(ROOM_STATES[1], ROOM_STATES[2]);
    this->addStateChange(ROOM_STATES[2], ROOM_STATES[3]);
    this->addStateChange(ROOM_STATES[3], ROOM_STATES[2]);
    this->addStateChange(ROOM_STATES[2], ROOM_STATES[0]);
}

Hotel::~Hotel()
{
    deleteRooms();
    delete state_graph_;
    state_graph_ = nullptr;
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

// Add room state change as an edge in a graph
void Hotel::addStateChange(std::string source_state, std::string destination_state)
{
    int source_index = getIndex(source_state);
    int destination_index = getIndex(destination_state);

    if(source_index != -1 && destination_index != -1)
    {
        state_graph_->addEdge(source_index, destination_index);
    }
};

void Hotel::printStateGraph()
{
    state_graph_->printGraph();
}

std::string Hotel::assignRoom()
{
    for(auto room : rooms_)
    {
        if(room->state_ == room_states_[0])
        {
            if(state_graph_->checkEdge(0, 1))
            {
                room->state_ = room_states_[1];
                return room->name_;
            }
            else
            {
                std::cout << "No edge from " << room_states_[0] << " to " << room_states_[1] << " in state graph" << std::endl;
                return "";
            }
        }
    }
    std::cout << "No available rooms" << std::endl;
    return "";
}

bool Hotel::setState(std::string room_name, int source_index, int destination_index)
{
    // Check if room states exists
    if(source_index >= room_states_.size() || destination_index >= room_states_.size())
    {
        std::cout << "Invalid source index or destination index" << std::endl;
        return false;
    }

    for(auto room : rooms_)
    {
        if(room->name_ == room_name)
        {
            if(room->state_ == room_states_[source_index])
            {
                // Check if room state change exists
                if(state_graph_->checkEdge(getIndex(room->state_), destination_index))
                {
                    room->state_ = room_states_[destination_index];
                    return true;
                }
                else
                {
                    std::cout << "State of room " << room_name << ": " << room->state_ << std::endl;
                    std::cout << "No edge from " << room->state_ << " to " << room_states_[destination_index] << " in state graph" << std::endl;
                    std::cout << "Operation invalid" << std::endl;
                    return false;
                }
            }
            else
            {
                std::cout << "State of room " << room_name << " is " << room->state_ << ", not " << room_states_[source_index] << std::endl;
                std::cout << "Operation invalid" << std::endl;
                return false;
            }
        }
    }
    std::cout << "No room named " << room_name << std::endl;
    return false;
}

bool Hotel::checkOut(std::string room_name)
{
    return setState(room_name, 1, 2);
}

bool Hotel::setAvailable(std::string room_name)
{
    return setState(room_name, 2, 0);
}

bool Hotel::setRepair(std::string room_name)
{
    return setState(room_name, 2, 3);
}

bool Hotel::setVacant(std::string room_name)
{
    return setState(room_name, 3, 2);
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
    rooms_.clear();
}

int Hotel::getIndex(std::string state)
{
    auto it = std::find(room_states_.begin(), room_states_.end(), state);

    // If element is found
    if (it != room_states_.end())
    {
        // Calculating the index
        int index = it - room_states_.begin();
        return index;
    }
    else
    {
        // If the element is not found
        return -1;
    }
}