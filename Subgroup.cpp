#include "Subgroup.h"

int Subgroup::counterId = 0;

Subgroup::Subgroup(string title): id(++counterId) {
    this->title = title;
}

int Subgroup::getId() const {
    return this->id;
}

string Subgroup::getTitle() const {
    return this->title;
}
