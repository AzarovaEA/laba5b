#include "libs/vector.h"
#include <stdio.h>
#include <stdint.h>
#include "assert.h"


void test_pushBack_emptyVector() {
    vector v = createVector(0);

    assert(isEmpty(&v) == 1);

    pushBack(&v, 2);
    assert(v.data[0] == 2);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);

    pushBack(&v, 2);
    assert(isFull(&v) == 1);
    assert(v.data[0] == 2);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(1);

    pushBack(&v, 2);
    pushBack(&v, 3);
    assert (v.size == 2);
    popBack(&v);
    assert (v.size == 1);
    assert (v.capacity == 2);
    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(2);

    pushBack(&v, 2);
    pushBack(&v, 3);
    assert (v.size == 2);
    atVector(&v, 0);
    assert(!isEmpty(&v));
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);

    pushBack(&v, 2);
    pushBack(&v, 3);
    assert (v.size == 2);
    assert(*atVector(&v, 1) == 3);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);

    pushBack(&v, 2);
    assert (v.size == 1);
    assert(*back(&v) == 2);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);

    pushBack(&v, 9);
    assert (v.size == 1);
    assert(*front(&v) == 9);
    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}
