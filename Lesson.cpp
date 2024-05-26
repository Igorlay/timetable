#include "Lesson.h"

using namespace std;

Lesson::Lesson(const Discipline &discipline, const int &groupId, const int &roomId, const int &order,
               const WeekChanges &weekChanges, const LESSON_TYPE &lessonType, const int &teacherId,
               const int &dayOfWeek,
               const string &timeFrom, const string &timeTo)
    : discipline(discipline), groupId(groupId), roomId(roomId), order(order), weekChanges(weekChanges),
      lessonType(lessonType), teacherId(teacherId), dayOfWeek(dayOfWeek), timeFrom(timeFrom), timeTo(timeTo) {}

Lesson::Lesson(const Discipline &discipline, const int &groupId, const int &subgroupId, const int &roomId,
               const int &order, const WeekChanges &weekChanges, const LESSON_TYPE &lessonType, const int &teacherId,
               const int &dayOfWeek, const string &timeFrom, const string &timeTo)
    : discipline(discipline), groupId(groupId), subgroupId(subgroupId), roomId(roomId), order(order),
      weekChanges(weekChanges), lessonType(lessonType), teacherId(teacherId), dayOfWeek(dayOfWeek),
      timeFrom(timeFrom), timeTo(timeTo) {}

Discipline Lesson::getDiscipline() const {
    return this->discipline;
}

int Lesson::getGroupId() const {
    return this->groupId;
}

int Lesson::getSubgroupId() const {
    return this->subgroupId;
}

int Lesson::getRoomId() const {
    return this->roomId;
}

int Lesson::getOrder() const {
    return this->order;
}

WeekChanges Lesson::getWeekChanges() const {
    return this->weekChanges;
}

LESSON_TYPE Lesson::getLessonType() const {
    return this->lessonType;
}

int Lesson::getTeacherId() const {
    return this->teacherId;
}

int Lesson::getDayOfWeek() const {
    return this->dayOfWeek;
}

string Lesson::getTimeFrom() const {
    return this->timeFrom;
}

string Lesson::getTimeTo() const {
    return this->timeTo;
}

void Lesson::setDiscipline(const Discipline &discipline) {
    this->discipline = discipline;
}

void Lesson::setGroupId(const int &groupId) {
    this->groupId = groupId;
}

void Lesson::setSubgroupId(const int &subgroupId) {
    this->subgroupId = subgroupId;
}

void Lesson::setRoomId(const int &roomId) {
    this->roomId = roomId;
}

void Lesson::setOrder(const int &order) {
    this->order = order;
}

void Lesson::setWeekChanges(const WeekChanges &weekChanges) {
    this->weekChanges = weekChanges;
}

void Lesson::setLessonType(const LESSON_TYPE &lessonType) {
    this->lessonType = lessonType;
}

void Lesson::setTeacherId(const int &teacherId) {
    this->teacherId = teacherId;
}

void Lesson::setDayOfWeek(const int &dayOfWeek) {
    this->dayOfWeek = dayOfWeek;
}

void Lesson::setTimeFrom(const string &timeFrom) {
    this->timeFrom = timeFrom;
}

void Lesson::setTimeTo(const string &timeTo) {
    this->timeTo = timeTo;
}

bool Lesson::operator==(const Lesson &lesson) const {
    return this->discipline.getUniqueId() == lesson.discipline.getUniqueId() &&
           this->groupId == lesson.groupId &&
           this->subgroupId == lesson.subgroupId &&
           this->roomId == lesson.roomId &&
           this->order == lesson.order &&
           this->weekChanges == lesson.weekChanges &&
           this->lessonType == lesson.lessonType &&
           this->teacherId == lesson.teacherId &&
           this->dayOfWeek == lesson.dayOfWeek &&
           this->timeFrom == lesson.timeFrom &&
           this->timeTo == lesson.timeTo;
}

bool Lesson::operator!=(const Lesson &lesson) const {
    return !(*this == lesson);
}

bool Lesson::operator<(const Lesson &lesson) const {
    return this->order < lesson.order;
}

bool Lesson::operator>(const Lesson &lesson) const {
    return this->order > lesson.order;
}

bool Lesson::operator<=(const Lesson &lesson) const {
    return !(*this > lesson);
}

bool Lesson::operator>=(const Lesson &lesson) const {
    return !(*this < lesson);
}
