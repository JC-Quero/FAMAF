#include <stdio.h>

int ingrese_enteros(void) {
    int x;
    printf("Ingrese su entero: ");
    scanf("%d", &x);
    return x;
}

int main(void) {
    int x = ingrese_enteros();
    int y = ingrese_enteros();
    int z;  

    
    z = x;
    x = y;
    y = z;

    
    printf("Despues del intercambio:\n");
    printf("x es igual a: %d\n", x);
    printf("y es igual a: %d\n", y);

    return 0;
}
