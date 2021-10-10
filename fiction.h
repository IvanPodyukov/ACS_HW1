#ifndef __fiction__
#define __fiction__

// fiction.h - содержит описание игрового фильма

#include <stdio.h>

// Игровой фильм
struct fiction {
    char producer[15];
};

// Считывание очередного игрового фильма из файла
void InFiction(struct fiction *f, FILE *file);

// Генерация очередного игрового фильма
void InRndFiction(struct fiction *f);

// Вывод информации об очередном игровом фильме в файл
void OutFiction(struct fiction *m, FILE *file);

#endif
