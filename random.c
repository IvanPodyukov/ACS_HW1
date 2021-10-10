#include "random.h"
#include "string.h"

// Генерация типа фильма/мультфильма
int RandomType() {
    return rand() % 3 + 1;
}

// Генерация года выхода фильма
int RandomYear() {
    return rand() % 90 + 1930;
}

// Генерация длины научного фильма в минутах
int RandomLengthOfMovie() {
    return rand() % 90 + 60;
}

// Генерация рандомного символа
char RandomChar() {
    const char symbols_for_name[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    return symbols_for_name[rand() % strlen(symbols_for_name)];
}
