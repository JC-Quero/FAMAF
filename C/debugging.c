#include <stdio.h>
#include <stdbool.h>

int Entero(void){
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

int Booleano(void){
    int tempX;
    printf("Ingrese un valor booleano: ");
    scanf("%d", &tempX);
    bool x = tempX;
    return x;
}

int main(void){
    int x = Entero();
    int y = Entero();
    int z = Entero();

    bool b = Booleano();
    bool w = Booleano();

    printf("x % 4 == 0 = ");
    printf("%d\n", (x%4) == 0);

    printf("x + 1 == 0 && y - x == (-1) * z = ");
    printf("%d\n", x+1 == 0 && y-x == (-1) *z);

    printf("not b && w = ");
    printf("%d\n", !b && w);

    return 0;
}
/*
Ingrese un valor entero: 4
Ingrese un valor entero: -4
Ingrese un valor entero: 8
Ingrese un valor booleano: 1
Ingrese un valor booleano: 1
x % 4 == 0 = 1
x + 1 == 0 && y - x == (-1) * z = 0
not b && w = 0
*/