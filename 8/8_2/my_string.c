unsigned int my_strlen(const char* string) // вычисляет длину строки
{
    unsigned int i;

    for (i = 0; *(string + i) != 0; i++);
    return i;
}

int my_strcmp(const char* s1, const char *s2) // сравнивает строки, 0 - равенство
{
    unsigned int i;

    for (i = 0; *(s1 + i) && (*(s1 + i) == *(s2 + i)); i++);
    return *(s1 + i) - *(s2 + i);
}
