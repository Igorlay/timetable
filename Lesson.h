#ifndef TIMETABLE_LESSON_H
#define TIMETABLE_LESSON_H

#include "Discipline.h"
#include "Group.h"
#include "LessonType.h"
#include "WeekChanges.h"

class Lesson {
private:
    Discipline discipline;
    int groupId;
    int subgroupId = -1;
    int roomId;
    int order;
    WeekChanges weekChanges;
    LESSON_TYPE lessonType;
    int teacherId;
    int dayOfWeek;
    string timeFrom;
    string timeTo;

public:
    Lesson(const Discipline &discipline, const int &groupId, const int &roomId, const int &order,
           const WeekChanges &weekChanges, const LESSON_TYPE &lessonType, const int &teacherId, const int &dayOfWeek,
           const string &timeFrom, const string &timeTo);

    Lesson(const Discipline &discipline, const int &groupId, const int &subgroupId, const int &roomId, const int &order,
           const WeekChanges &weekChanges, const LESSON_TYPE &lessonType, const int &teacherId, const int &dayOfWeek,
           const string &timeFrom, const string &timeTo);

    Discipline getDiscipline() const;

    int getGroupId() const;

    int getSubgroupId() const;

    int getRoomId() const;

    int getOrder() const;

    WeekChanges getWeekChanges() const;

    LESSON_TYPE getLessonType() const;

    int getTeacherId() const;

    int getDayOfWeek() const;

    string getTimeFrom() const;

    string getTimeTo() const;

    void setDiscipline(const Discipline &discipline);

    void setGroupId(const int &groupId);

    void setSubgroupId(const int &subgroupId);

    void setRoomId(const int &roomId);

    void setOrder(const int &order);

    void setWeekChanges(const WeekChanges &weekChanges);

    void setLessonType(const LESSON_TYPE &lessonType);

    void setTeacherId(const int &teacherId);

    void setDayOfWeek(const int &dayOfWeek);

    void setTimeFrom(const string &timeFrom);

    void setTimeTo(const string &timeTo);

    bool operator==(const Lesson &lesson) const;

    bool operator!=(const Lesson &lesson) const;

    bool operator<(const Lesson &lesson) const;

    bool operator>(const Lesson &lesson) const;

    bool operator<=(const Lesson &lesson) const;

    bool operator>=(const Lesson &lesson) const;
};

#endif //TIMETABLE_LESSON_H
