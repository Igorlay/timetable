#include <iostream>

#include "Teacher.h"
#include "Group.h"
#include "Timetable.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Room room16(16, ROOM_TYPE::CABINET, 20);
    Room room20(20, ROOM_TYPE::LECTURE_AUDIENCE, 100);

    Teacher kn22Supervisor("Константин", "Сурков", "Юрійович");
    Teacher kn23Supervisor("Макруха", "Тетяна", "Сергіївна");

    Teacher teacher1("Іванов", "Іван", "Іванович");

    Group kn22Group("КН-22", kn22Supervisor);
    Group kn23Group("КН-23", kn23Supervisor);

    Subgroup kn22FirstSubgroup = Subgroup("Перша підгрупа");
    kn22Group.addSubgroup(kn22FirstSubgroup);

    Lesson lesson1 = Lesson(
        Discipline("Програмування"),
        kn22Group.getUniqueId(),
        room16.getUniqueId(),
        1,
        WeekChanges::NO_CHANGES,
        LESSON_TYPE::PRACTICE,
        kn22Supervisor.getUniqueId(),
        DayOfWeek::MONDAY,
        "08:30",
        "10:00"
    );

    Lesson lesson2 = Lesson(
        Discipline("Хімія"),
        kn23Group.getUniqueId(),
        room20.getUniqueId(),
        1,
        WeekChanges::NUMERATOR,
        LESSON_TYPE::LECTION,
        kn23Supervisor.getUniqueId(),
        DayOfWeek::MONDAY,
        "08:30",
        "10:00"
    );

    Lesson lesson3 = Lesson(
        Discipline("Компʼютерні мережі"),
        kn22Group.getUniqueId(),
        kn22FirstSubgroup.getId(),
        room16.getUniqueId(),
        2,
        WeekChanges::NO_CHANGES,
        LESSON_TYPE::LABORATORY,
        teacher1.getUniqueId(),
        DayOfWeek::TUESDAY,
        "10:10",
        "11:40"
    );

    Timetable timetable;
    timetable.addGroup(kn22Group);
    timetable.addGroup(kn23Group);

    timetable.addTeacher(kn22Supervisor);
    timetable.addTeacher(kn23Supervisor);
    timetable.addTeacher(teacher1);

    timetable.addLesson(lesson1);
    timetable.addLesson(lesson2);
    timetable.addLesson(lesson3);

    cout << timetable;

    cout << "Видалення групи КН-22...\n\n";
    timetable.removeGroup(kn22Group);

    cout << timetable;

    return 0;
}
