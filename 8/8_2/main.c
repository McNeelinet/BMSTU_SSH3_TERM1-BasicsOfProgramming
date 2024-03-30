#include <stdio.h>
#include <malloc.h>
#include "my_string.h"

char** inputNames(int* len);
char* inputString();
char** replaceInFirstWords(char** names, int len);
char* delNChar(char* string, int n);
void printNames(char** matrix, int rows, char* title);
void freeWords(char** matrix, int rows);

int main()
{
    int len;
    char** names = inputNames(&len);

    if (names != NULL) {
        names = replaceInFirstWords(names, len);
        if (names != NULL) {
            printNames(names, len, "Names list:");
            freeWords(names, len);
        }
    }

    return 0;
}

void freeWords(char** matrix, int rows)
{
    for (int row = 0; (row <= rows - 1) && *(matrix + row); row++)
        free(*(matrix + row));
    free(matrix);
}

char* inputString()
{
    char* string = (char*) malloc(sizeof(char));
    char* temp = string;
    int len = 0;
    char ch = getchar();

    while (ch != '\n') {
        if (string != NULL) {
            temp = string;
            *(string + len++) = ch;
            string = (char*) realloc(string, (len + 1) * sizeof(char));
        }
        ch = getchar();
    }
    if (string != NULL)
        *(string + len) = '\0';
    else
        free(temp);

    return string;
}

char** inputNames(int* len)
{
    char** names = (char**) malloc(sizeof(char*));
    char** temp;
    char* name;
    *len = 0;

    puts("Enter \"stop\" to stop:");
    if (names != NULL) {
        name = inputString();
        while (name != NULL && my_strcmp(name, "stop") != 0) {
            *(names + (*len)++) = name;
            temp = names;
            names = (char**) realloc(names, sizeof(char*) * (*len + 1));
            if (names == NULL) {
                freeWords(temp, (*len) + 1);
                break;
            }
            name = inputString();
        }
        free(name);
    }
    if (!(*len)) {
        free(names);
        names = NULL;
    }

    return names;
}

void swap(char* chr1, char* chr2)
{
    char temp = *chr1;
    *chr1 = *chr2;
    *chr2 = temp;
}

void printNames(char** matrix, int rows, char* title)
{
    printf("%s\n", title);

    for (int row = 0; row <= rows - 1; row++)
        puts(*(matrix + row));
}

char* addNChar(char* string, int n)
{
    char* temp = string;
    int len = my_strlen(string);

    string = (char*) realloc(string, ((len++) + 2) * sizeof(char));
    if (string != NULL) {
        *(string + len) = ' ';
        for (int i = len; i >= n + 1; i--) {
            swap(string + i - 1, string + i);
        }
    }
    else
        free(temp);

    return string;
}

char* delNChar(char* string, int n)
{
    char* temp = string;
    int len = my_strlen(string);

    for (int i = n; i <= len - 1; i++)
        swap(string + i, string + i + 1);
    string = (char*) realloc(string, len * sizeof(char));
    if (string == NULL)
        free(temp);

    return string;
}

char* replaceInFirstWord(char* string, char* suf1, char* suf2)
{
    int difference = my_strlen(suf2) - my_strlen(suf1);
    int j;

    if (my_strlen(string) > 1)
        for (int i = 1; (*(string + i) != ' ');) {
            for (j = 0; *(suf1 + j) && (*(string + i + j) == *(suf1 + j)); j++);
            if (!*(suf1 + j)) {
                for (int t = difference; t > 0 && string != NULL; t--)
                    string = addNChar(string, i);
                for (int t = difference; t < 0 && string != NULL; t++)
                    string = delNChar(string, i);
                if (string != NULL)
                    for (int x = 0; *(suf2 + x); x++) {
                        *(string + i) = *(suf2 + x);
                        i++;
                    }
                else
                    break;
            }
            else
                i++;
        }

    return string;
}

char** replaceInFirstWords(char** names, int len)
{
    printf("suf1: ");
    char* suf1 = inputString();
    printf("suf2: ");
    char* suf2 = inputString();

    if (suf1 != NULL && suf2 != NULL)
        for (int i = 0; i <= len - 1; i++) {
            *(names + i) = replaceInFirstWord(*(names + i), suf1, suf2);
            if (*(names + i) == NULL) {
                freeWords(names, len);
                names = NULL;
                break;
            }
        }

    if (suf1 != NULL)
        free(suf1);
    if (suf2 != NULL)
        free(suf2);

    return names;
}
