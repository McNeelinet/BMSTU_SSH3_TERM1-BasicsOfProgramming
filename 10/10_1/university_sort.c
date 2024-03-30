#include <string.h>
#include "university_struct.h"


void swapGroups(struct group_t* group1_p, struct group_t* group2_p)
{
    struct group_t temp = *group1_p;
    *group1_p = *group2_p;
    *group2_p = temp;
}

void sortGroups(struct university_t* university)
{
    for (int i = 0; i <= university->n - 1; i++)
        for (int j = 0; j <= university->n - 2 - i; j++)
            if (university->groups[j]->lowestMark < university->groups[j + 1]->lowestMark)
                swapGroups(university->groups[j], university->groups[j + 1]);
}

void swapStudents(struct student_t* student1_p, struct student_t* student2_p)
{
    struct student_t temp = *student1_p;
    *student1_p = *student2_p;
    *student2_p = temp;
}

void sortStudents(struct university_t* university)
{
    struct group_t* group;
    struct student_t* students;

    for (int i = 0; i <= university->n - 1; i++) {
        group = university->groups[i];
        students = group->students;
        for (int j = 0; j <= group->n - 1; j++)
            for (int k = j; k <= group->n - 2; k++)
                if (strcmp(students[k].name, students[k + 1].name) > 0)
                    swapStudents(students + k, students + k + 1);
    }
}
