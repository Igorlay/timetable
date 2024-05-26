#include "Human.h"

Human::Human() {
    this->firstName = "";
    this->lastName = "";
    this->middleName = "";
}

Human::Human(const string &firstName, const string &lastName, const string &middleName) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->middleName = middleName;
}

ostream &operator<<(ostream &out, const Human &human) {
    out << human.firstName << " "
        << human.lastName << " "
        << human.middleName << "\n";

    return out;
}

istream &operator>>(istream &in, Human &human) {
    string buffer;

    cout << "Enter the first name: ";
    in >> human.firstName;

    cout << "Enter the last name: ";
    in >> human.lastName;

    cout << "Enter the middle name: ";
    in >> human.middleName;

    return in;
}

