#ifndef MY_STRING_H
#define MY_STRING_H

unsigned int my_strlen(const char* string);
char* my_strcpy(char* dst, const char* src);
char* my_strcat(char* dst, const char* src);
int my_strcmp(const char* s1, const char *s2);
char* my_strchr(char* str, char ch);
char* my_strstr(char* str, char* sub_str);
char* my_strpbrk(char* str, char* sym);


#endif // MY_STRING_H
