#include <stdio.h>
    
int pedirEntero(void){
    int x;
    printf("Ingrese un numero entero: ");
    scanf("%d", &x);
    return x;
}

void Ejercicio1e(void){
    int x = pedirEntero();
    int y = pedirEntero();

    printf("El estado inicial de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    if(x>=y){
        printf("(x>=y)\n");

        printf("El primer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);
        x = 0;
        printf("El segundo estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    }else if(x < y){
        printf("(x<y)\n");

        printf("El primer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);
        x = 2;
        printf("El segundo estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    }
    printf("El tercer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

}

void Ejercicio1f(void){
    int x = pedirEntero();
    int y = pedirEntero();

    printf("El estado inicial de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    if(x>=y){
        printf("(x>=y)\n");

        printf("El primer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);
        x = 0;
        printf("El segundo estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    }else if(x < y){
        printf("(x<y)\n");

        printf("El primer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);
        x = 2;
        printf("El segundo estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);

    }
    printf("El tercer estado de x es : (x->%d) y el de y es: (y->%d)\n", x,y);
}


int main (void){    
    Ejercicio1e();
    Ejercicio1f();

    return 0;
}
/*
S E:\FAMAF\Proyecto3> gcc -Wall -Wextra -std=c99 .\condi.c -o ej4
PS E:\FAMAF\Proyecto3> .\ej4.exe
Ingrese un numero entero: 3
Ingrese un numero entero: 1
El estado inicial de x es : (x->3) y el de y es: (y->1)
(x>=y)
El primer estado de x es : (x->3) y el de y es: (y->1)
El segundo estado de x es : (x->0) y el de y es: (y->1)
El tercer estado de x es : (x->0) y el de y es: (y->1)
Ingrese un numero entero: -100
Ingrese un numero entero: 1
El estado inicial de x es : (x->-100) y el de y es: (y->1)
(x<y)
El primer estado de x es : (x->-100) y el de y es: (y->1)
El segundo estado de x es : (x->2) y el de y es: (y->1)
El tercer estado de x es : (x->2) y el de y es: (y->1)

*/