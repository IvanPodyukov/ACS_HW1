// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
// Формат ввода данных о фильме:
// Через пробел вводятся четыре параметра:
// Первый - число (тип фильма в диапазоне от 1 до 3)
// 1 - игровой, 2 - мультфильм, 3 - научный
// Второй - строка (название фильма)
// Третий - число (год выхода фильма)
// Четвертый зависит от типа фильма:
// Если тип фильма мультфильм или научный, то
// Четвертым параметром является число
// Для мультфильма это его тип (1 - рисованный, 2 - кукольный, 3 - пластилиновый)
// Для научного фильма это его длина в минутах
// Если тип фильма игровой, то четвертым параметром является строка - имя режиссёра
// Пример входных данных:
// 1 Fiction1 2019 Producer1 3 Science1 2014 123
// В контейнер будут добавлены игровой фильм "Fiction1" режиссёра Procuder1 2019 года
// И научный фильм 2014 года с названием "Science1" длиной в 123 минуты.


#include <stdio.h>
#include "container.h"
#include <stdlib.h>
#include <string.h>

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile\n"
           "  Or:\n"
           "     command -n number outfile\n");
}

int main(int argc, char *argv[]) {
    // Проверка на корректное количество входных данных
    if (argc != 4) {
        errMessage1();
        return 1;
    }
    printf("Start\n");
    struct container c;
    Init(&c);
    if (!strcmp(argv[1], "-f")) {
        FILE *infile = fopen(argv[2], "a+");
        // Заполнение контейнера входными данными.
        In(&c, infile);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d", size);
            printf(". Set 0 < number <= 10000\n");
            return 3;
        }
        srand(time(NULL));
        // Заполнение контейнера данными, созданными генератором рандомных чисел
        InRnd(&c, (int) size);
    }
    FILE *outfile = fopen(argv[3], "a+");
    fprintf(outfile, "Filled container: ");
    // Вывод содержимого заполненного контейнера в файл.
    Out(&c, outfile);
    fprintf(outfile, "\n\nAverage quotient = ");
    fprintf(outfile, "%f", SumOfQuotients(&c) / c.len);
    DeleteElementsWithQuotientLessThanAverage(&c);
    fprintf(outfile, "\nChanged container: ");
    // Вывод содержимого изменённого контейнера в файл.
    Out(&c, outfile);
    fclose(outfile);
    Clear(&c);
    printf("Stop\n");
    printf("Seconds: %f", ((double)(clock() - start_time)) / CLOCKS_PER_SEC);
    return 0;
}
