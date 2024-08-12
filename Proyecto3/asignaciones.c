#include <stdio.h>
#include <assert.h>

int pedirEntero(void){
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

void Ejercicio1a(void){
    int x = pedirEntero();
    assert(x==1);

    printf("El estado inicial es: (x->%d)\n", x);
    x = 5;
    printf("El segundo estado es: (x->%d)\n", x);
}

void Ejercicio1b(void){
    int x =  pedirEntero();
    int y = pedirEntero();
    assert(x == 2 && y == 5);

    printf("El estado inicial de x es: (x-> %d) y el de y es: (y->%d)\n", x, y);
    x = x+y;
    printf("El segundo estado de x es: (x->%d) y el de y es: (y->%d)\n", x,y);
    y = y + y;
    printf("El tercer estado de x es: (x->%d) y el de y es: (y->%d)\n", x,y);

}

void Ejercicio1c(void){
    int x = pedirEntero();
    int y = pedirEntero();
    assert(x==2 && y == 5);

    printf("El estado inicial de x es: (x-> %d) y el de y es: (y->%d)\n", x, y);
    y = y + y;
    printf("El segundo estado de x es: (x->%d) y el de y es: (y->%d)\n", x,y);
    x = x + y;
    printf("El tercer estado de x es: (x->%d) y el de y es: (y->%d)\n", x,y);

}

int main(void){
  Ejercicio1a();
  Ejercicio1b();
  Ejercicio1c();

  return 0;
}
/*
PS E:\FAMAF\Proyecto3> gcc -Wall -Wextra -std=c99 .\asignaciones.c -o ej3
PS E:\FAMAF\Proyecto3> .\ej3.exe
Ingrese un valor entero: 1
El estado inicial es: (x->1)
El segundo estado es: (x->5)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
El estado inicial de x es: (x-> 2) y el de y es: (y->5)
El segundo estado de x es: (x->7) y el de y es: (y->5)
El tercer estado de x es: (x->7) y el de y es: (y->10)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
El estado inicial de x es: (x-> 2) y el de y es: (y->5)
El segundo estado de x es: (x->2) y el de y es: (y->10)
El tercer estado de x es: (x->12) y el de y es: (y->10)
*/