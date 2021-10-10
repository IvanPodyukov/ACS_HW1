#ifndef __movie__
#define __movie__

// movie.h - содержит описание обобщённого фильма

#include "fiction.h"
#include "cartoon.h"
#include "science.h"
#include "string.h"
#include "movie.h"

// Обобщённый фильм
struct movie {
    enum key_of_movie {
        FICTION = 1, CARTOON = 2, SCIENCE = 3
    };
    enum key_of_movie k;
    int year;
    char name[15];
    int length_of_name;
    // Используемые альтернативы
    union {
        struct fiction f;
        struct cartoon c;
        struct science s;
    };
};

// Считывание очередного обобщенного фильма из файла
struct movie *InMovie(FILE *file);

// Генерация очередного обобщённого фильма
struct movie *InRndMovie();

// Вывод информации об очередном обобщённом фильме в файл
void OutMovie(struct movie *m, FILE *file);

// Функция, общая для всех альтернатив
double Quotient(struct movie *m);

#endif
