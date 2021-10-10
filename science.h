#ifndef __science__
#define __science__

// science.h - содержит описание научного фильма

#include <stdio.h>

// Научный фильм
struct science {
    int length_of_movie_in_minutes;
};

// Считывание очередного научного фильма из файла
void InScience(struct science *s, FILE *file);

// Генерация очередного научного фильма
void InRndScience(struct science *s);

// Вывод информации об очередном научном фильме в файл
void OutScience(struct science *m, FILE *file);

#endif
