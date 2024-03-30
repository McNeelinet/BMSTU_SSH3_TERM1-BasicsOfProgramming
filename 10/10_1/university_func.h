#ifndef UNIVERSITY_FUNC_H
#define UNIVERSITY_FUNC_H
#include "university_struct.h"

void freeUniversity(struct university_t* university);
struct university_t* initUniversity();
struct university_t* fillUniversity(struct university_t*);
void printUniversity(struct university_t* university, char* title);
struct university_t* dismissStudents(struct university_t* university, int badMark, int limit);

#endif // UNIVERSITY_FUNC_H
