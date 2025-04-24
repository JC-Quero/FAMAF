#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },                               // test 0: arreglo de 1 solo elemento
        { {1, 3, 2}, 3, 1 },                         // Test 1: cima en el medio
        { {1, 2, 3, 4, 3, 2, 1}, 7, 3 },             // Test 2: cima en el centro
        { {2, 4, 6, 5, 3, 1}, 6, 2 },                // Test 3: cima hacia la izquierda
        { {1, 5, 10, 7, 6, 4}, 6, 2 },               // Test 4: cima clara
        { {1, 2, 1}, 3, 1 },                         // Test 5: cima mínima válida
        { {1, 4, 6, 8, 7, 5, 2}, 7, 3 },             // Test 6: subida y bajada larga
        { {1, 100, 90}, 3, 1 },                      // Test 7: números grandes
        { {-5, -3, 0, -1, -6}, 5, 2 },               // Test 8: con negativos
        { {5, 10, 15, 12, 8, 3, 1}, 7, 2 }           // Test 9: cima más a la izquierda

        // COMPLETAR!!

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
