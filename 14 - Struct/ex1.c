#include "PointersLibs.h"

#define MAXSIZE 256
#define MAT_SIZE 6

struct study_hours
{
    string teacher;
    unsigned short subject;
    int total_students;
};

unsigned int TeachesCountMaxHoursStraightInDay(struct study_hours *ptr_mat_day, unsigned short rows, unsigned short cols)
{
    unsigned short max = ZERO;
    unsigned short counter = ONE;
    struct study_hours *ptr_temp = ptr_mat_day + cols;
    rows--;
    while (rows--)
    {
        if (!StringCompare(&((*ptr_mat_day).teacher), &((*ptr_temp).teacher))) 
        {
            max = (counter > max) ? counter : max;
            counter = ZERO;
        }
        counter++;
        ptr_mat_day += cols;
        ptr_temp += cols;
    }
    
    return (max);
}

struct study_hours * TeachesMaxHoursStraightInDay(struct study_hours *ptr_mat_day, unsigned short rows, unsigned short cols)
{
    unsigned short counter = ONE,
                    max = ZERO;
    struct study_hours *ptr_temp = ptr_mat_day + cols;
    struct study_hours *ptr_max_teacher = ptr_mat_day;
    rows--;
    while (rows--)
    {
        if (!StringCompare(&((*ptr_mat_day).teacher), &((*ptr_temp).teacher)))
        { 
            max = (counter > max) ? counter : max;
            counter = ZERO;
        }
        counter++;
        ptr_mat_day += cols;
        ptr_temp += cols;
    }
    
    return (ptr_max_teacher);
}

// Ex1
struct study_hours * WhoTeachesMoreThanFourHoursStraight(struct study_hours *ptr_mat, unsigned short rows, unsigned short cols)
{
    unsigned short day = cols;
    while (TeachesCountMaxHoursStraightInDay(ptr_mat++, rows, cols) < FIVE && day--);

    return (TeachesMaxHoursStraightInDay(--ptr_mat, rows, cols));
}

unsigned short TeacherCountOfHoursInDay(struct study_hours *ptr_mat, unsigned short rows, unsigned short cols, string teacher)
{
    unsigned short counter = ZERO;
    rows--;
    while (rows--)
    {
        counter += StringCompare(&((*ptr_mat).teacher), teacher);
        ptr_mat += cols;
    }
    
    return (counter);
}

// Ex2
unsigned short TeacherCountOfHoursInWeek(struct study_hours *ptr_mat, unsigned short rows, unsigned short cols, string teacher)
{
    unsigned short counter = ZERO;
    unsigned short day = cols;
    while (day--)
    {
        counter += TeacherCountOfHoursInDay(ptr_mat++, rows, cols, teacher);
    }

    return counter;
}

int CountStudentsInSubjectOnDay(struct study_hours *ptr_mat, unsigned short rows, unsigned short cols, unsigned short subject)
{
    int counter = ZERO;
    rows--;
    while (rows--)
    {
        counter += ((*ptr_mat).subject == subject) ? (*ptr_mat).total_students : ZERO;
        ptr_mat += cols;
    }
    
    return (counter);
}

int CountStudentsInSubjectOnWeek(struct study_hours *ptr_mat, unsigned short rows, unsigned short cols, unsigned short subject)
{
    int total_students = ZERO;
    unsigned short days = cols;
    while (days--)
    {
        total_students += CountStudentsInSubjectOnDay(ptr_mat, rows, cols, subject);
    }
    
    return (total_students);
}

void main(void)
{
    string vec_subjects[MAXSIZE];
}