#include <stdio.h>

int Entero(void) {
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

int main(void) {
    int x = Entero();
    int y = Entero();
    int z = Entero();

    printf("x + y + 1 = ");
    printf("%d\n", x + y + 1);

    printf("z * z + y * 45 - 15 * x = ");
    printf("%d\n", z * z + y * 45 - 15 * x);

    printf("y - 2 == (x * 3 + 1) %% 5 = ");
    printf("%d\n", y - 2 == (x * 3 + 1) % 5);

    printf("y / 2 * x = ");
    printf("%d\n", y / 2 * x);

    printf("y < x *z = ");
    printf("%d\n", y < x *z);
    return 0;
}