#include "hotel.hpp"

std::vector<std::string> ROOM_STATES = {"Available", "Occupied", "Vacant", "Repair"};
std::vector<std::pair<std::string, int>> ROOMS = {std::make_pair("1A", 0), std::make_pair("1B", 0), std::make_pair("1C", 0), std::make_pair("1D", 0), std::make_pair("1E", 0),
                                                  std::make_pair("2E", 0), std::make_pair("2D", 0), std::make_pair("2C", 0), std::make_pair("2B", 0), std::make_pair("2A", 0),
                                                  std::make_pair("3A", 0), std::make_pair("3B", 0), std::make_pair("3C", 0), std::make_pair("3D", 0), std::make_pair("3E", 0),
                                                  std::make_pair("4E", 0), std::make_pair("4D", 0), std::make_pair("4C", 0), std::make_pair("4B", 0), std::make_pair("4A", 0)};

int main()
{
    Hotel hotel(ROOM_STATES);
    hotel.addRooms(ROOMS);
    hotel.addStateChange(ROOM_STATES[0], ROOM_STATES[1]);
    hotel.addStateChange(ROOM_STATES[1], ROOM_STATES[2]);
    hotel.addStateChange(ROOM_STATES[2], ROOM_STATES[3]);
    hotel.addStateChange(ROOM_STATES[3], ROOM_STATES[2]);
    hotel.addStateChange(ROOM_STATES[2], ROOM_STATES[0]);

    std::cout << "Print room state graph:" << std::endl;
    hotel.printStateGraph();

    std::cout << "Available rooms: ";
    for(auto room : hotel.listAvailableRooms())
    {
        std::cout << room << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned room: " << hotel.assignRoom() << std::endl;

    std::cout << "Available rooms: ";
    for(auto room : hotel.listAvailableRooms())
    {
        std::cout << room << " ";
    }
    std::cout << std::endl;

    std::cout << "End" << std::endl;
    return 0;
}