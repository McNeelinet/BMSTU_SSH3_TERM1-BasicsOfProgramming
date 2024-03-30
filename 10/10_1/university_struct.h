#ifndef UNIVERSITY_STRUCT_H
#define UNIVERSITY_STRUCT_H

struct student_t
{
    int marks[5];
    char name[41];

    float average;
};

struct group_t
{
    int lowestMark;

    int n;
    struct student_t* students;
};

struct university_t
{
    int n;
    struct group_t** groups;
};

#endif // UNIVERSITY_STRUCT_H
