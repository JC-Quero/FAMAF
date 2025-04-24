#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        {{8}, 1, false },
        {{1, 3, 5, 6, 2}, 5, true},
        {{5, 4, 3, 2, 1}, 5, false},
        {{1, 2, 3, 4, 5}, 5, false},
        {{1, 3, 2}, 3, true},
        {{1, 2}, 2, false},
        {{5}, 1, false},
        {{1, 2, 2, 1}, 4, false},  // No subida estricta
        {{1, 3, 2, 2}, 4, false},  // No bajada estricta
        {{2, 4, 6, 5, 3, 1}, 6, true}

    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },
        { {1, 3, 5, 6, 2}, 5, 3 },
        { {2, 4, 6, 5, 3, 1}, 6, 2 },
        { {1, 3, 2}, 3, 1 },
        { {1, 5, 10, 7, 6, 4}, 6, 2 },
        { {0, 2, 4, 3}, 4, 2 },
        { {1, 2, 1}, 3, 1 },
        { {1, 4, 6, 8, 7, 5, 2}, 7, 3 },
        { {1, 100, 90}, 3, 1 },
        { {2, 3, 5, 7, 6}, 5, 3 }

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
