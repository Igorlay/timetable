#include "Group.h"

int Group::counterId = 0;

Group::Group(): id(++counterId) {
    this->title = "";
    this->supervisor = Teacher();
}

int Group::getUniqueId() const {
    return this->id;
}

Group::Group(const string &title, const Teacher &supervisor): id(++counterId) {
    this->title = title;
    this->supervisor = supervisor;
}

void Group::setSupervisor(const Teacher &teacher) {
    this->supervisor = teacher;
}

Teacher Group::getSupervisor() const {
    return this->supervisor;
}

string Group::getTitle() const {
    return this->title;
}

void Group::setTitle(const string &title) {
    this->title = title;
}

void Group::addSubgroup(const Subgroup &subgroup) {
    this->subgroups.push_back(subgroup);
}

void Group::clearSubgroups() {
    this->subgroups = {};
}

vector<Subgroup> Group::getSubgroups() const {
    return this->subgroups;
}

Subgroup* Group::getSubgroupById(const int &subgroupId) {
    for (int i = 0; i < this->subgroups.size(); i++) {
        if (this->subgroups[i].getId() == subgroupId) {
            return &this->subgroups[i];
        }
    }

    return nullptr;
}

void Group::removeSubgroupById(const int &subgroupId) {
    for (int i = 0; i < this->subgroups.size(); i++) {
        if (this->subgroups[i].getId() == subgroupId) {
            this->subgroups.erase(this->subgroups.begin() + i);
            break;
        }
    }
}
