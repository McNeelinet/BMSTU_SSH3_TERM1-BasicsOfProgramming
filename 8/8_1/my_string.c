unsigned int my_strlen(const char* string) // вычисляет длину строки
{
    unsigned int i;

    for (i = 0; *(string + i) != 0; i++);
    return i;
}

char* my_strchr(char* str, char ch) // возвращает указатель на первый символ ch в строке
{
    char* ptr;

    for (ptr = str; *ptr && *ptr != ch; ptr++);
    return ptr;
}
