// container.c - содержит функции обработки контейнера

#include "container.h"
#include "movie.h"

// Инициализация контейнера
void Init(struct container *c) {
    c->len = 0;
}

// Очистка контейнера
void Clear(struct container *c) {
    c->len = 0;
}

// Ввод обобщённых фильмов в контейнер
void In(struct container *c, FILE *file) {
    while ((c->cont[c->len] = InMovie(file)) != NULL) {
        c->len++;
    }
    fclose(file);
}

// Генерация обобщённых фильмов для контейнера
void InRnd(struct container *c, int size) {
    while (c->len < size) {
        c->cont[c->len] = InRndMovie();
        c->len++;
    }

}

// Вывод информации об обобщённых фильмах, содержащихся в контейнере, в файл
void Out(struct container *c, FILE *file) {
    fprintf(file, "Container contains ");
    fprintf(file, "%d", c->len);
    fprintf(file, " elements.");
    for (int i = 0; i < c->len; i++) {
        fprintf(file, "\n%d", i + 1);
        fprintf(file, ": ");
        OutMovie(c->cont[i], file);
    }
}

// Обработка данных в контейнере (удаление неподходящих элементов)
void DeleteElementsWithQuotientLessThanAverage(struct container *c) {
    double average = SumOfQuotients(c) / c->len;
    for (int i = 0; i < c->len; i++) {
        if (Quotient(c->cont[i]) < average) {
            c->len--;
            for (int j = i; j < c->len; j++) {
                c->cont[j] = c->cont[j + 1];
            }
            c->cont[c->len] = NULL;
            i--;
        }
    }
}

// Сумма частных всех обобщенных фильмов контейнера
double SumOfQuotients(struct container *c) {
    double sum = 0;
    for (int i = 0; i < c->len; i++) {
        sum += Quotient(c->cont[i]);
    }
    return sum;
}

