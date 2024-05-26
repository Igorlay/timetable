#ifndef TIMETABLE_GROUP_H
#define TIMETABLE_GROUP_H

#include <vector>

#include "Subgroup.h"
#include "Teacher.h"

using namespace std;

class Group {
private:
    string title;
    Teacher supervisor;
    vector<Subgroup> subgroups;
    static int counterId;
    int id;

public:
    Group();

    Group(const string &, const Teacher &);

    void setSupervisor(const Teacher &);

    Teacher getSupervisor() const;

    string getTitle() const;

    void setTitle(const string &);

    void addSubgroup(const Subgroup &);

    void clearSubgroups();

    vector<Subgroup> getSubgroups() const;

    Subgroup* getSubgroupById(const int &);

    void removeSubgroupById(const int &);

    int getUniqueId() const;
};

#endif //TIMETABLE_GROUP_H
