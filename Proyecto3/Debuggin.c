#include <stdio.h>
#include <stdbool.h>

int pedirEntero(void){
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

int pedirBooleano(void){
    int tempX;
    printf("Ingrese un valor booleano: ");
    scanf("%d", &tempX);
    bool x = tempX;
    return x;
}

int main(void){
    int x = pedirEntero();
    int y = pedirEntero();
    int z = pedirEntero();

    bool b = pedirBooleano();
    bool w = pedirBooleano();

    printf("x %% 4 == 0 = ");
    printf("%d\n", (x % 4) == 0);

    printf("x + y == 0 && y - x == (-1) * z = ");
    printf("%d\n", x + y == 0 && y - x == (-1) *z);

    printf("not b && w = ");
    printf("%d\n", !b && w);

    return 0;
}

/*
Ejemplo de ejecucion

Ingrese un valor entero: 4
Ingrese un valor entero: -4
Ingrese un valor entero: 8
Ingrese un valor booleano: 1
Ingrese un valor booleano: 1
x % 4 == 0 = 1
x + y == 0 && y - x == (-1) * z = 1
not b && w = 0
*/