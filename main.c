#include "libs/vector.h"
#include <stdio.h>
#include <stdint.h>

int main() {
    vector v = createVector(5);

    printf("%lld\n", v.size);

    clear(&v);

    printf("%lld", v.size);

    return 0;
}
