#include <stdio.h>
#include "university_struct.h"
#include "university_func.h"
#include "university_sort.h"


int main()
{
    struct university_t* bmstu = initUniversity();
    if (bmstu != NULL) {
        bmstu = fillUniversity(bmstu);
        if (bmstu != NULL) {
            // 10.1
            printUniversity(bmstu, "\nBMSTU:");
            sortGroups(bmstu);
            sortStudents(bmstu);
            printUniversity(bmstu, "\nBMSTU after sort:");

            // 10.2
            bmstu = dismissStudents(bmstu, 2, 2);
            if (bmstu != NULL) {
                printUniversity(bmstu, "\nBMSTU after session:");
                freeUniversity(bmstu);
            }
        }
    }
    return 0;
}
