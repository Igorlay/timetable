#include <algorithm>
#include "Timetable.h"

using namespace std;

Timetable::Timetable() {
    this->groups = {};
    this->rooms = {};
    this->lessons = {};
    this->teachers = {};
}

Timetable::Timetable(vector<Group> groups): Timetable() {
    this->groups = groups;
}

Timetable::Timetable(vector<Room> rooms): Timetable() {
    this->rooms = rooms;
}

Timetable::Timetable(vector<Group> groups, vector<Room> rooms, vector<Lesson> lessons, vector<Teacher> teachers) {
    this->groups = groups;
    this->rooms = rooms;
    this->lessons = lessons;
    this->teachers = teachers;
}

void Timetable::addGroup(const Group &group) {
    this->groups.push_back(group);
}

void Timetable::removeGroup(const Group &group) {
    for (int i = 0; i < this->groups.size(); i++) {
        if (this->groups[i].getUniqueId() == group.getUniqueId()) {
            this->groups.erase(this->groups.begin() + i);
        }
    }

    for (int i = 0; i < this->lessons.size(); i++) {
        if (this->lessons[i].getGroupId() == group.getUniqueId()) {
            this->lessons.erase(this->lessons.begin() + i);
        }
    }
}

void Timetable::addLesson(const Lesson &lesson) {
    this->lessons.push_back(lesson);
}

void Timetable::removeLesson(const Lesson &lesson) {
    for (int i = 0; i < this->lessons.size(); i++) {
        if (this->lessons[i] == lesson) {
            this->lessons.erase(this->lessons.begin() + i);
        }
    }
}

void Timetable::addTeacher(const Teacher &teacher) {
    this->teachers.push_back(teacher);
}

void Timetable::removeTeacher(const Teacher &teacher) {
    for (int i = 0; i < this->teachers.size(); i++) {
        if (this->teachers[i].getUniqueId() == teacher.getUniqueId()) {
            this->teachers.erase(this->teachers.begin() + i);
        }
    }
}

ostream &operator<<(ostream &out, Timetable &t) {
    vector<Lesson> sortedLessons = t.lessons;

    sort(sortedLessons.begin(), sortedLessons.end(), [](const Lesson &a, const Lesson &b) {
        if (a.getDayOfWeek() == b.getDayOfWeek()) {
            return a.getOrder() < b.getOrder();
        }
        return a.getDayOfWeek() < b.getDayOfWeek();
    });

    for (Group &group : t.groups) {
        out << "Група: " << group.getTitle() << "\n";

        int previousDay = -1;
        for (const Lesson &lesson: sortedLessons) {
            if (lesson.getGroupId() == group.getUniqueId()) {
                if (lesson.getDayOfWeek() != previousDay) {
                    out << Timetable::getPrintableDayOfWeek(static_cast<DayOfWeek>(lesson.getDayOfWeek()));
                    out << ": \n";
                    previousDay = lesson.getDayOfWeek();
                }

                out << lesson.getOrder() << " пара - ";
                out << lesson.getTimeFrom() << " - " << lesson.getTimeTo() << " ";
                out << lesson.getDiscipline().getName() << '.';

                if (lesson.getWeekChanges() != WeekChanges::NO_CHANGES) {
                    out << " (";
                    out << (lesson.getWeekChanges() == WeekChanges::NUMERATOR ? "чисельник" : "знаменник");
                    out << ") ";
                }

                Subgroup *subgroup = group.getSubgroupById(lesson.getSubgroupId());
                if (subgroup != nullptr) {
                    out << " (" << subgroup->getTitle() << ") ";
                }

                for (const Teacher &teacher : t.teachers) {
                    if (teacher.getUniqueId() == lesson.getTeacherId()) {
                        out << "\nВикладач: ";
                        out << teacher;
                    }
                }

                out << endl;
            }
        }

        out << endl;
    }

    return out;
}

string Timetable::getPrintableDayOfWeek(DayOfWeek dayOfWeek) {
    switch (dayOfWeek) {
        case MONDAY:
            return "Понеділок";
        case TUESDAY:
            return "Вівторок";
        case WEDNESDAY:
            return "Середа";
        case THURSDAY:
            return "Четвер";
        case FRIDAY:
            return "Пʼятниця";
        case SATURDAY:
            return "Субота";
        case SUNDAY:
            return "Неділя";
    }

    cout << "Помилка. Невизначенний день.\n";
    exit(1);
}
