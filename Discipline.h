#ifndef TIMETABLE_DISCIPLINE_H
#define TIMETABLE_DISCIPLINE_H

#include <string>

using namespace std;

class Discipline {
private:
    static int currentId;
    int id;
    string name;

public:
    Discipline(string name);

    int getUniqueId() const;

    string getName() const;
};

#endif //TIMETABLE_DISCIPLINE_H
