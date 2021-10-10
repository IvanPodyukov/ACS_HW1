// fiction.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного игрового фильма

#include "fiction.h"
#include "random.h"

// Считывание очередного игрового фильма из файла
void InFiction(struct fiction *f, FILE *file) {
    fscanf(file, "%s", f->producer);
}

// Генерация очередного игрового фильма
void InRndFiction(struct fiction *f) {
    int length = rand() % 10 + 6;
    for (int i = 0; i < length; i++) {
        f->producer[i] = RandomChar();
    }
    f->producer[length] = '\0';
}

// Вывод информации об очередном игровом фильме в файл
void OutFiction(struct fiction *m, FILE *file) {
    fprintf(file, "\nProducer = ");
    fprintf(file, "%s", m->producer);
}
