#ifndef TIMETABLE_TEACHER_H
#define TIMETABLE_TEACHER_H

#include "Human.h"

using namespace std;

class Teacher : public Human {
private:
    static int counterId;
    int id;

public:
    Teacher();

    Teacher(const string &, const string &, const string &);

    int getUniqueId() const;
};

#endif //TIMETABLE_TEACHER_H