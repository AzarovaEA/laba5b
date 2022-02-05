#include "libs/vector.h"
#include <stdio.h>
#include <stdint.h>
#include "assert.h"

int main() {
    vector v = createVector(5);

    pushBack(&v, 0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 9);
    pushBack(&v, 4);
    pushBack(&v, 5);

    int *a = atVector(&v, 5);
    printf("%d", *a);

    return 0;
}
