#include "Discipline.h"

int Discipline::currentId = 0;

Discipline::Discipline(string name): id(++currentId) {
    this->name = name;
}

int Discipline::getUniqueId() const {
    return this->id;
}

string Discipline::getName() const {
    return this->name;
}
