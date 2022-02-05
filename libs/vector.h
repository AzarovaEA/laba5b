#ifndef LABA5B_VECTOR_H
#define LABA5B_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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

// возвращает значение true, если вектор v пустой,
// в противном случае возвращает значение false
bool isEmpty(vector *v);

// возвращает значение true, если вектор v заполненный,
// в противном случае возвращает значение false
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v.
// Если вектор заполнен, увеличивает количество
// выделенной ему памяти в 2 раза
void pushBack(vector *v, int x);

//  удаляет последний элемент из вектора v
void popBack(vector *v);

#endif //LABA5B_VECTOR_H
