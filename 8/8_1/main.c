#include <stdio.h>
#include <malloc.h>
#include "my_string.h"

char* inputString();
int myStrlen(const char* string);
char* deleteExcessSpaces(char* string);

int main()
{
    char* string = inputString();

    if (string != NULL) {
        printf("%d\n", my_strlen(string));
        string = deleteExcessSpaces(string);
        if (string != NULL) {
            printf("|%s|\n", string);
            printf("%d\n", my_strlen(string));
            free(string);
        }
    }

    return 0;
}

char* inputString()
{
    char* string = (char*) malloc(sizeof(char));
    char* temp = string;
    int len = 0;
    char ch;

    puts("Введите вашу строку: ");
    ch = getchar();

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

char* deleteChar(char* string, int pos)
{
    int size = my_strlen(string);

    for (int i = pos; i <= size - 1; i++)
       *(string + i) = *(string + i + 1);

    if (size) {
        char* temp = string;
        string = (char*) realloc(string, size * sizeof(char));
        if (string == NULL)
            free(temp);
    }

    return string;
}

char* lStrip(char* string)
{
    while (*string == ' ')
        if (string != NULL)
            string = deleteChar(string, 0);
        else
            break;

    return string;
}

char* rStrip(char* string)
{
    int lastPos = my_strlen(string) - 1;

    while (lastPos >= 0 && *(string + lastPos) == ' ')
        if (string != NULL) {
            string = deleteChar(string, lastPos);
            lastPos -= 1;
        }
        else
            break;

    return string;
}

char* deleteExcessSpaces(char* string)
{
    int leftDelMarker;
    int rightDelMarker;
    int len = my_strlen(string);

    for (int i = 1; i <= len - 2; i++)
        if (string != NULL) {
            if (*(string + i) != ' ')
                continue;

            leftDelMarker = *my_strchr(" -(", *(string + i - 1));
            rightDelMarker = *my_strchr(" ,.?!:-;)", *(string + i + 1));

            if (leftDelMarker || rightDelMarker) {
                string = deleteChar(string, i);
                i--; len--;
            }
        }
        else
            break;

    if (string != NULL)
        string = lStrip(string);
    if (string != NULL)
        string = rStrip(string);

    return string;
}
