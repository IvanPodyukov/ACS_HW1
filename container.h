#ifndef __container__
#define __container__

// container.h - содержит описание контейнера

#include <stdio.h>

// Контейнер
struct container {
    enum {
        max_len = 10000
    };
    int len;
    struct movie *cont[max_len];
};

// Инициализация контейнера
void Init(struct container *c);

// Очистка контейнера
void Clear(struct container *c);

// Ввод обобщённых фильмов в контейнер
void In(struct container *c, FILE *file);

// Генерация обобщённых фильмов для контейнера
void InRnd(struct container *c, int size);

// Вывод информации об обобщённых фильмах, содержащихся в контейнере, в файл
void Out(struct container *c, FILE *file);

// Сумма частных всех обобщенных фильмов контейнера
double SumOfQuotients(struct container *c);

// Обработка данных в контейнере (удаление неподходящих элементов)
void DeleteElementsWithQuotientLessThanAverage(struct container *c);

#endif
