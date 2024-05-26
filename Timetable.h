#ifndef TIMETABLE_TIMETABLE_H
#define TIMETABLE_TIMETABLE_H

#include <vector>

#include "Lesson.h"
#include "Group.h"
#include "Room.h"
#include "DayOfWeek.h"

using namespace std;

class Timetable;

ostream &operator<<(ostream &out, Timetable &t);

class Timetable {
private:
    vector<Group> groups;
    vector<Room> rooms;
    vector<Lesson> lessons;
    vector<Teacher> teachers;

    static string getPrintableDayOfWeek(DayOfWeek dayOfWeek);

public:
    Timetable();

    Timetable(vector<Group> groups);

    Timetable(vector<Room> rooms);

    Timetable(vector<Group> groups, vector<Room> rooms, vector<Lesson> lessons, vector<Teacher> teachers);

    void addGroup(const Group &group);

    void removeGroup(const Group &group);

    void addLesson(const Lesson &lesson);

    void removeLesson(const Lesson &lesson);

    void addTeacher(const Teacher &teacher);

    void removeTeacher(const Teacher &teacher);

    friend ostream &operator<<(ostream &os, Timetable &t);
};

#endif //TIMETABLE_TIMETABLE_H
