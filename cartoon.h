#ifndef __cartoon__
#define __cartoon__

// cartoon.h - содержит описание мультфильма

#include <stdio.h>

// Мультфильм
struct cartoon {
    enum type_of_cartoon {
        DRAWN = 1, PUPPET = 2, PLASTICINE = 3
    };
    enum type_of_cartoon type;

};

// Считывание очередного мультфильма из файла
void InCartoon(struct cartoon *c, FILE *file);

// Генерация очередного мультфильма
void InRndCartoon(struct cartoon *c);

// Вывод информации об очередном мультфильме в файл
void OutCartoon(struct cartoon *m, FILE *file);

#endif
