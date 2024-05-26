#include "Teacher.h"

int Teacher::counterId = 0;

Teacher::Teacher() : id(++counterId), Human() {
}

Teacher::Teacher(const string &firstName, const string &lastName, const string &thirdName) :
        id(++counterId),
        Human(firstName, lastName, thirdName) {
}

int Teacher::getUniqueId() const {
    return this->id;
}
