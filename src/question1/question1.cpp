#include "hotel.hpp"

const std::vector<std::pair<std::string, int>> ROOMS =
{
    std::make_pair("1A", 0), std::make_pair("1B", 0), std::make_pair("1C", 0), std::make_pair("1D", 0), std::make_pair("1E", 0),
    std::make_pair("2E", 0), std::make_pair("2D", 0), std::make_pair("2C", 0), std::make_pair("2B", 0), std::make_pair("2A", 0),
    std::make_pair("3A", 0), std::make_pair("3B", 0), std::make_pair("3C", 0), std::make_pair("3D", 0), std::make_pair("3E", 0),
    std::make_pair("4E", 0), std::make_pair("4D", 0), std::make_pair("4C", 0), std::make_pair("4B", 0), std::make_pair("4A", 0)
};

int main()
{
    // Initialize Hotel object
    Hotel hotel;
    hotel.addRooms(ROOMS);

    // List available rooms
    std::cout << "Hotel initialized." << std::endl;
    std::cout << "Available rooms: ";
    for(auto room : hotel.listAvailableRooms())
    {
        std::cout << room << " ";
    }
    std::cout << std::endl;

    // Keyboard input instructions
    std::cout << "Keyboard inputs:" << std::endl;
    std::cout << "1: Check in" << std::endl;
    std::cout << "2: Check out" << std::endl;
    std::cout << "3: Mark room as cleaned" << std::endl;
    std::cout << "4: Mark room for repair" << std::endl;
    std::cout << "5: Mark room as repaired" << std::endl << std::endl;

    // Execution loop
    std::string keyboard_input;
    while(true)
    {
        std::cout << "Enter a number between 1 and 5: ";
        std::getline(std::cin, keyboard_input);

        if(keyboard_input.size() == 1)
        {
            switch(keyboard_input[0])
            {
                case '1':
                    std::cout << "Selected \"Check in\". Assigned room: " << hotel.assignRoom() << std::endl;
                    break;
                case '2':
                    std::cout << "Selected \"Check out\". Enter a room name: ";
                    std::getline(std::cin, keyboard_input);
                    if(hotel.checkOut(keyboard_input))
                    {
                        std::cout << "Checked out of room " << keyboard_input << std::endl;
                    }
                    break;
                case '3':
                    std::cout << "Selected \"Mark room as cleaned\". Enter a room name: ";
                    std::getline(std::cin, keyboard_input);
                    if(hotel.setAvailable(keyboard_input))
                    {
                        std::cout << "Room " << keyboard_input << " marked as cleaned" << std::endl;
                    }
                    break;
                case '4':
                    std::cout << "Selected \"Mark room for repair\". Enter a room name: ";
                    std::getline(std::cin, keyboard_input);
                    if(hotel.setRepair(keyboard_input))
                    {
                        std::cout << "Room " << keyboard_input << " marked for repair" << std::endl;
                    }
                    break;
                case '5':
                    std::cout << "Selected \"Mark room as repaired\". Enter a room name: ";
                    std::getline(std::cin, keyboard_input);
                    if(hotel.setVacant(keyboard_input))
                    {
                        std::cout << "Room " << keyboard_input << " marked as repaired" << std::endl;
                    }
                    break;
                default:
                    std::cout << "Invalid input, please retry." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input, please retry." << std::endl;
        }
        std::cout << "Available rooms: ";
        for(auto room : hotel.listAvailableRooms())
        {
            std::cout << room << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl << "####################" << std::endl;
    }
    return 0;
}