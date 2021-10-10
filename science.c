// science.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного научного фильма

#include "science.h"
#include "random.h"

// Считывание очередного научного фильма из файла
void InScience(struct science *s, FILE *file) {
    fscanf(file, "%d", &s->length_of_movie_in_minutes);
}

// Генерация очередного научного фильма
void InRndScience(struct science *s) {
    s->length_of_movie_in_minutes = RandomLengthOfMovie();
}

// Вывод информации об очередном научном фильме в файл
void OutScience(struct science *m, FILE *file) {
    fprintf(file, "\nLength_of_movie_in_minutes = ");
    fprintf(file, "%d", m->length_of_movie_in_minutes);

}

