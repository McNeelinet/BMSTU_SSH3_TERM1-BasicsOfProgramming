#include <malloc.h>
#include <string.h>
#include "university_struct.h"


void freeUniversity(struct university_t* university)
{
    for (int i = 0; i <= university->n - 1; i++) {
        if (university->groups[i] != NULL) {
            if (university->groups[i]->students != NULL)
                free(university->groups[i]->students);
            free(university->groups[i]);
        }
    }
    free(university);
}

void clearStdin()
{
    char check;

    do {
        check = getchar();
    }
    while (check != '\n');
}

int inputMark()
{
    int mark;
    int check;

    do {
        check = scanf("%d", &mark);
        clearStdin();
        if (check != 1)
            printf("You should input a digit! Try again: ");
        else if ((mark < 1) || (mark > 5))
            printf("You should input a digit from 1 to 5. Try again: ");

    }
    while(check != 1 || (mark < 1) || (mark > 5));

    return mark;
}

struct university_t* initUniversity()
{
    struct university_t* university = (struct university_t*) malloc(sizeof(struct university_t));

    if (university != NULL) {
        university->n = 0;
        university->groups = NULL;
    }
    return university;
}

void my_gets(char* string, int len)
{
    int filledLen = 0;
    char ch = getchar();

    while (ch != '\n') {
        if (filledLen <= len - 2)
            *(string + filledLen++) = ch;
        ch = getchar();
    }
    *(string + filledLen) = '\0';
}

float findAverage(int* marks, int n)
{
    float sum = 0;

    for (int i = 0; i <= n - 1; i++)
        sum += marks[i];

    return sum / n;
}

struct student_t createStudent()
{
    struct student_t student;

    printf("Student's name is: ");
    my_gets(student.name, 41);

    if (strcmp(student.name, "stop")) {
        for (int i = 0; i <= 4; i++) {
            printf("Student's \"%s\" mark %d: ", student.name, i + 1);
            student.marks[i] = inputMark();
        }

        student.average = findAverage(student.marks, 5);
    }

    return student;
}

int findLowestMark(struct student_t student)
{
    int lowestMark = 5;
    for (int i = 0; i <= 4; i++)
        if (student.marks[i] < lowestMark)
            lowestMark = student.marks[i];

    return lowestMark;
}

struct group_t* findGroup(struct university_t university, int mark)
{
    struct group_t* group = NULL;

    for (int i = 0; i <= university.n - 1; i++) {
        if (university.groups[i]->lowestMark == mark)
            group = university.groups[i];
    }
    return group;
}

struct university_t* addGroup(struct university_t* univer, int marker)
{
    struct group_t** tmp = univer->groups;

    univer->groups = (struct group_t**) realloc(univer->groups, (univer->n + 1) * sizeof(struct group_t*));
    if (univer->groups != NULL) {
        univer->groups[univer->n] = (struct group_t*) malloc(sizeof(struct group_t));
        if (univer->groups[univer->n] != NULL) {
            univer->groups[univer->n]->lowestMark = marker;
            univer->groups[univer->n]->n = 0;
            univer->groups[univer->n]->students = NULL;

            univer->n += 1;
        }
        else
            univer = NULL;
    }
    else {
        for (int i = 0; i <= univer->n - 1; i++) {
            free(tmp[i]->students);
            free(tmp[i]);
            tmp[i] = NULL;
        }
        univer = NULL;
    }

    return univer;
}

struct group_t* addStudent(struct group_t* group, struct student_t student)
{
    struct student_t* tmp = group->students;

    group->students = (struct student_t*) realloc(group->students, (group->n + 1) * sizeof(struct student_t));
    if (group->students != NULL) {
        group->students[group->n] = student;
        group->n += 1;
    }
    else {
        free(tmp);
        free(group);
        group = NULL;
    }

    return group;
}

struct university_t* fillUniversity(struct university_t* university)
{
    puts("To stop input set student's name to \"stop\":");
    struct university_t* tmp = university;
    struct student_t student = createStudent();
    int lowestMark;
    struct group_t* group;

    while (strcmp(student.name, "stop")) {
        lowestMark = findLowestMark(student);
        group = findGroup(*university, lowestMark);
        if (group == NULL) {
            university = addGroup(university, lowestMark);
            if (university == NULL) {
                freeUniversity(tmp);
                break;
            }
            group = (university->groups)[university->n - 1];
        }
        group = addStudent(group, student);
        if (group == NULL) {
            university = NULL;
            freeUniversity(tmp);
            break;
        }
        student = createStudent();
    }

    return university;
}

void printUniversity(struct university_t* university, char* title)
{
    struct group_t* group;

    puts(title);
    for (int i = 0; i <= university->n - 1; i++) {
        group = university->groups[i];
        printf("Group with lowest mark %d:\n", group->lowestMark);
        for (int j = 0; j <= group->n - 1; j++) {
            printf("Name: %-40s", group->students[j].name);
            printf("\tMarks: ");
            for (int k = 0; k <= 4; k++)
                printf("%d ", group->students[j].marks[k]);
            printf("\tAverage: %.2lf", group->students[j].average);
            printf("\n");
        }
        printf("\n");
    }
}

int countLowerMarks(struct student_t student, int mark)
{
    int counter = 0;

    for (int i = 0; i <= 4; i++)
        if (student.marks[i] <= mark)
            counter++;

    return counter;
}

struct group_t* deleteStudent(struct group_t* group, int n)
{
    struct student_t* tmp = group->students;

    for (int i = n; i <= group->n - 2; i++)
        group->students[i] = group->students[i + 1];

    if (group->n - 1) {
        group->students = (struct student_t*) realloc(group->students, (group->n - 1) * sizeof(struct student_t));
        if (group->students != NULL)
            group->n -= 1;
        else {
            free(tmp);
            free(group);
            group = NULL;
        }
    }
    else {
        free(group->students);
        group->students = NULL;
        group->n = 0;
    }

    return group;
}

struct university_t* dismissStudents(struct university_t* university, int badMark, int limit)
{
    struct group_t* group;
    struct student_t student;

    for (int i = 0; i <= university->n - 1; i++) {
        for (int j = 0; j <= university->groups[i]->n - 1; j++) {
            student = university->groups[i]->students[j];
            if (countLowerMarks(student, badMark) > limit) {
                university->groups[i] = deleteStudent(university->groups[i], j);
                if (university->groups[i] == NULL) {
                    freeUniversity(university);
                    return NULL;
                }
            }
        }
    }

    return university;
}
