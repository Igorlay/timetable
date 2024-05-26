#ifndef TIMETABLE_HUMAN_H
#define TIMETABLE_HUMAN_H

#include <iostream>
#include <string>

using namespace std;

class Human;

ostream &operator<<(ostream &out, const Human &human);

istream &operator>>(istream &in, Human &human);

class Human {
private:
    string firstName;
    string lastName;
    string middleName;

public:
    Human();

    Human(const string &, const string &, const string &);

    friend ostream &operator<<(ostream &out, const Human &human);

    friend istream &operator>>(istream &in, Human &human);
};

#endif //TIMETABLE_HUMAN_H