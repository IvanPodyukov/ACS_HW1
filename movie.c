// movie.c - содержит процедуры связанные с обработкой обобщенного фильма
// и создания произвольной фильма

#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "random.h"

// Считывание очередного обобщенного фильма из файла
struct movie * InMovie(FILE *file) {
    struct movie *m;
    int type = 0;
    int year;
    m = (struct movie *) malloc(sizeof(struct movie));
    fscanf(file, "%d%s%d", &type, m->name, &year);
    if (type == 1) {
        m->k = FICTION;
        InFiction(&(m->f), file);
    } else if (type == 2) {
        m->k = CARTOON;
        InCartoon(&(m->c), file);
    } else if (type == 3) {
        m->k = SCIENCE;
        InScience(&(m->s), file);
    } else{
        return NULL;
    }
    m->year = year;
    m->length_of_name = strlen(m->name);
    return m;
}

// Генерация очередного обобщённого фильма
struct movie* InRndMovie() {
    int type = RandomType();
    struct movie *m;
    m = (struct movie *) malloc(sizeof(struct movie));
    if (type == 1) {
        m->k = FICTION;
        InRndFiction(&(m->f));
    } else if (type == 2) {
        m->k = CARTOON;
        InRndCartoon(&(m->c));
    } else if (type == 3) {
        m->k = SCIENCE;
        InRndScience(&(m->s));
    }
    int length = rand() % 10 + 6;
    for (int i = 0; i < length; i++) {
        m->name[i] = RandomChar();
    }
    m->length_of_name = length;
    m->name[length] = '\0';
    m->year = RandomYear();
}

// Вывод информации об очередном обобщённом фильме в файл
void OutMovie(struct movie *m, FILE *file) {
    fprintf(file, "It is a ");
    if (m->k == 1) {
        fprintf(file, "fiction");
    } else if (m->k == 2) {
        fprintf(file, "cartoon");
    } else {
        fprintf(file, "science");
    }
    fprintf(file, "\nName = ");
    fprintf(file, "%s", m->name);
    fprintf(file, "\nYear = ");
    fprintf(file, "%d", m->year);
    fprintf(file, "\nQuotient = ");
    fprintf(file, "%f", Quotient(m));
    if (m->k == FICTION) {
        OutFiction(&m->f, file);
    } else if (m->k == CARTOON) {
        OutCartoon(&m->c, file);
    } else if (m->k == SCIENCE) {
        OutScience(&m->s, file);
    }

}

// Функция, общая для всех альтернатив
double Quotient(struct movie *m) {
    return (double)(m->year) / m->length_of_name;
}
