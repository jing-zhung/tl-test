#include <gtest/gtest.h>
#include "hotel.hpp"

const std::vector<std::pair<std::string, int>> ROOMS = 
{
    std::make_pair("A", 0),
    std::make_pair("B", 0),
    std::make_pair("C", 0),
    std::make_pair("D", 0),
    std::make_pair("E", 0)
};

class HotelTest : public testing::Test
{
    protected:
        void SetUp() override
        {
            hotel_ptr = new Hotel;
            hotel_ptr->addRooms(ROOMS);
        }
        void TearDown() override
        {
            delete hotel_ptr;
        }
    Hotel* hotel_ptr;
};

TEST_F(HotelTest, AssignRoom)
{
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "A");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "B");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "C");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "D");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "E");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "");

    hotel_ptr->checkOut("C");
    hotel_ptr->setAvailable("C");
    EXPECT_STREQ(hotel_ptr->assignRoom().c_str(), "C");
}

TEST_F(HotelTest, CheckOut)
{
    std::string assigned_room = hotel_ptr->assignRoom();
    EXPECT_TRUE(hotel_ptr->checkOut(assigned_room));
    EXPECT_FALSE(hotel_ptr->checkOut(assigned_room));

    hotel_ptr->setRepair(assigned_room);
    EXPECT_FALSE(hotel_ptr->checkOut(assigned_room));

    hotel_ptr->setVacant(assigned_room);
    EXPECT_FALSE(hotel_ptr->checkOut(assigned_room));

    hotel_ptr->setAvailable(assigned_room);
    EXPECT_FALSE(hotel_ptr->checkOut(assigned_room));

    EXPECT_FALSE(hotel_ptr->checkOut("F"));
}

TEST_F(HotelTest, SetAvailable)
{
    std::string assigned_room = hotel_ptr->assignRoom();
    EXPECT_FALSE(hotel_ptr->setAvailable(assigned_room));

    hotel_ptr->checkOut(assigned_room);
    EXPECT_TRUE(hotel_ptr->setAvailable(assigned_room));
    EXPECT_FALSE(hotel_ptr->setAvailable(assigned_room));

    assigned_room = hotel_ptr->assignRoom();
    EXPECT_FALSE(hotel_ptr->setAvailable(assigned_room));

    hotel_ptr->checkOut(assigned_room);
    hotel_ptr->setRepair(assigned_room);
    EXPECT_FALSE(hotel_ptr->setAvailable(assigned_room));

    hotel_ptr->setVacant(assigned_room);
    EXPECT_TRUE(hotel_ptr->setAvailable(assigned_room));
    EXPECT_FALSE(hotel_ptr->setAvailable(assigned_room));

    EXPECT_FALSE(hotel_ptr->setAvailable("F"));
}

TEST_F(HotelTest, SetRepair)
{
    std::string assigned_room = hotel_ptr->assignRoom();
    EXPECT_FALSE(hotel_ptr->setRepair(assigned_room));

    hotel_ptr->checkOut(assigned_room);
    EXPECT_TRUE(hotel_ptr->setRepair(assigned_room));
    EXPECT_FALSE(hotel_ptr->setRepair(assigned_room));

    hotel_ptr->setVacant(assigned_room);
    EXPECT_TRUE(hotel_ptr->setRepair(assigned_room));
    EXPECT_FALSE(hotel_ptr->setRepair(assigned_room));

    hotel_ptr->setVacant(assigned_room);
    hotel_ptr->setAvailable(assigned_room);
    EXPECT_FALSE(hotel_ptr->setRepair(assigned_room));

    EXPECT_FALSE(hotel_ptr->setAvailable("F"));
}

TEST_F(HotelTest, SetVacant)
{
    std::string assigned_room = hotel_ptr->assignRoom();
    EXPECT_FALSE(hotel_ptr->setVacant(assigned_room));

    hotel_ptr->checkOut(assigned_room);
    EXPECT_FALSE(hotel_ptr->setVacant(assigned_room));

    hotel_ptr->setRepair(assigned_room);
    EXPECT_TRUE(hotel_ptr->setVacant(assigned_room));
    EXPECT_FALSE(hotel_ptr->setVacant(assigned_room));

    hotel_ptr->setAvailable(assigned_room);
    EXPECT_FALSE(hotel_ptr->setRepair(assigned_room));

    EXPECT_FALSE(hotel_ptr->setAvailable("F"));
}

TEST_F(HotelTest, ListAvailableRooms)
{
    std::vector<std::string> available_rooms = hotel_ptr->listAvailableRooms();
    EXPECT_STREQ(available_rooms[0].c_str(), "A");
    EXPECT_STREQ(available_rooms[1].c_str(), "B");
    EXPECT_STREQ(available_rooms[2].c_str(), "C");
    EXPECT_STREQ(available_rooms[3].c_str(), "D");
    EXPECT_STREQ(available_rooms[4].c_str(), "E");
}