#include <stdio.h>

int pedirEntero(void){
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

void Ejercicio2(void){
    int x = pedirEntero();
    int y = pedirEntero();
    int z = pedirEntero();
    int m = pedirEntero();

    printf("Estado inicial: (x->%d), (y->%d), (z->%d), (m->%d)\n", x,y,z,m);

    if(x<y){
        printf("x<y\n");
        m = x;
    }else{
        printf("x>=y\n");
        m = y;
    }
    printf("El primer estado: (x->%d), (y->%d), (z->%d), (m->%d)\n", x,y,z,m);

    if(m<z){
        printf("m < z\n");
    }else{
        printf("m >= z\n");
        m = z;
    }
    printf("El segundo estado: (x->%d), (y->%d), (z->%d), (m->%d)\n", x,y,z,m);
}

int main(void){
    Ejercicio2();
    return 0;
}
/*
PS E:\FAMAF\Proyecto3> gcc -Wall -Wextra -std=c99 .\condi2.c -o ej42
PS E:\FAMAF\Proyecto3> .\ej42.exe
Ingrese un valor entero: 5
Ingrese un valor entero: 4
Ingrese un valor entero: 8
Ingrese un valor entero: 0
Estado inicial: (x->5), (y->4), (z->8), (m->0)
x>=y
El primer estado: (x->5), (y->4), (z->8), (m->4)
m < z
El segundo estado: (x->5), (y->4), (z->8), (m->4)

*/