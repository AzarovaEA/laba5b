#ifndef LABA5B_VECTOR_H
#define LABA5B_VECTOR_H

#include <stdio.h>
#include <malloc.h>

typedef struct vector {
    int *data;        // указатель на элементы вектора
    size_t size;      // размер вектора
    size_t capacity;  // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет размер выделяемой памяти
// вектора v на newCapacity
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v,
// но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под
// неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает всю память, выделенную вектору v
void deleteVector(vector *v);

#endif //LABA5B_VECTOR_H
