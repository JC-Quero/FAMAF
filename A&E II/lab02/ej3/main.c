#include <stdio.h>
#include <stdlib.h>
#include "cima_log.h"

int main(void) {
    int a[] = {-2, 8, 9, 5, 0};
    int length = 5;
    int result;

    result = cima_log(a, length);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;

    /*
        a[0] = -2 → no puede ser cima (está al principio y a[1] > a[0])

        a[1] = 8 → 8 > -2 ✅ pero 8 < 9 ❌ → no es cima

        a[2] = 9 → 9 > 8 ✅ y 9 > 5 ✅ → ¡es la cima!

        a[3] = 5 → 5 < 9 ❌

        a[4] = 0 → último, pero tampoco cumple
    */
}
