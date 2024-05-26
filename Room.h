#ifndef TIMETABLE_ROOM_H
#define TIMETABLE_ROOM_H

#include "RoomTypes.h"

class Room {
private:
    ROOM_TYPE type;
    int number;
    int maxSeats;
    static int counterId;
    int id;

public:
    Room(int, ROOM_TYPE, int maxSeats);

    int getUniqueId() const;
};

#endif //TIMETABLE_ROOM_H
