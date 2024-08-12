#include <stdio.h>
#include <stdbool.h>

int pedirEntero(void){
    int x;
    printf("Ingrese un numero entero: ");
    scanf("%d", &x);
    return x;
}

int pedirBooleano(void){
    int temp;
    printf("Ingrese un valor entero booleano: ");
    scanf("%d", &temp);
    bool x = temp;
    return x;
}

void Ejercicio1(void){
    int x = pedirEntero();
    int y = pedirEntero();
    int i = pedirEntero();

    printf("El estado inicial es: (x->%d), (y->%d), (i->%d)\n", x,y,i);

    i = 0;
    while (x>=y){
        x = x - y;
        i = i+1;
        printf("El primer estado es %d: (x->%d), (y->%d), (i->%d)\n",i,x,y,i);
    }
}

void Ejercicio2(void){
    int x = pedirEntero();
    int i = pedirEntero();
    bool resultado = pedirBooleano();
    int itr = 0;

    printf("El estado inicial es: (x->%d), (i->%d), (resultado -> %d)\n", x,i, resultado);
    i = 2;
    resultado = 1;

    while((i<x) && resultado){
        resultado = resultado && ((x%i)!=0);
        i++;
        itr++;
        
        printf("El primer estado es %d : (x->%d), (i->%d), (resultado -> %d)\n", itr,x,i,resultado);
    }
}

int main(void){
    Ejercicio1();
    Ejercicio2();

    return 0;
}
/*
Resumen
Ejercicio1: Realiza una serie de restas de y a x hasta que x sea menor que y y cuenta las veces que se realizó la resta.
Ejercicio2: Verifica si un número x es primo comprobando si no es divisible por ningún número entre 2 y x-1.
Ambos programas utilizan funciones auxiliares para solicitar y recibir entradas del usuario y luego realizan iteraciones 
basadas en esas entradas, imprimiendo el estado de las variables en cada paso.



PS E:\FAMAF\Proyecto3> gcc -Wall -Wextra -std=c99 .\ciclos.c -o ej5
PS E:\FAMAF\Proyecto3> .\ej52.exe
Ingrese un numero entero: 7
Ingrese un numero entero: 2
Ingrese un numero entero: 0
El estado inicial es: (x->7), (y->2), (i->0)
El primer estado es: (x->5), (y->2), (i->1)
El primer estado es: (x->3), (y->2), (i->2)
El primer estado es: (x->1), (y->2), (i->3)
Ingrese un numero entero: 11
Ingrese un numero entero: 2
Ingrese un valor entero booleano: 1
El estado inicial es: (x->11), (i->2), (resultado -> 1)
El primer estado es 1 : (x->11), (i->3), (resultado -> 1)
El primer estado es 2 : (x->11), (i->4), (resultado -> 1)
El primer estado es 3 : (x->11), (i->5), (resultado -> 1)
El primer estado es 4 : (x->11), (i->6), (resultado -> 1)
El primer estado es 5 : (x->11), (i->7), (resultado -> 1)
El primer estado es 6 : (x->11), (i->8), (resultado -> 1)
El primer estado es 7 : (x->11), (i->9), (resultado -> 1)
El primer estado es 8 : (x->11), (i->10), (resultado -> 1)
El primer estado es 9 : (x->11), (i->11), (resultado -> 1)
*/