// cartoon.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного мультфильма

#include "cartoon.h"
#include "random.h"

// Считывание очередного мультфильма из файла
void InCartoon(struct cartoon *c, FILE *file) {
    fscanf(file, "%d", &c->type);
}

// Генерация очередного мультфильма
void InRndCartoon(struct cartoon *c) {
    c->type = RandomType();
}

// Вывод информации об очередном мультфильме в файл
void OutCartoon(struct cartoon *m, FILE *file) {
    fprintf(file, "\nCartoon type = ");
    if (m->type == DRAWN) {
        fprintf(file, "drawn");
    } else if (m->type == PUPPET) {
        fprintf(file, "puppet");
    } else {
        fprintf(file, "plasticine");
    }
}
