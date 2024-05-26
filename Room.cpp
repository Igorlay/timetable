#include "Room.h"

int Room::counterId = 0;

Room::Room(int number, ROOM_TYPE type, int maxSeats): id(++counterId) {
    this->number = number;
    this->type = type;
    this->maxSeats = maxSeats;
}

int Room::getUniqueId() const {
    return this->id;
}
