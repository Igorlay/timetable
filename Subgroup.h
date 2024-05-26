#ifndef TIMETABLE_SUBGROUP_H
#define TIMETABLE_SUBGROUP_H

#include <string>

using namespace std;

class Subgroup {
private:
    string title;
    static int counterId;
    int id;

public:
    Subgroup(string title);

    int getId() const;

    string getTitle() const;
};

#endif //TIMETABLE_SUBGROUP_H
