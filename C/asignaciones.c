#include <stdio.h>
#include <assert.h>

int Entero(void){
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

void Ejercicio1a(void){
    printf("Ejercicio 1)a)\n");
    int x = Entero();
   

    printf("El estado inicial es: (x->%d)\n", x);
    x = 5;
    printf("El segundo final es: (x->%d)\n", x);
}

void Ejercicio1b(void){
    printf("Ejercicio 1)b)\n");
    int x = Entero();
    int y = Entero();

    printf("El estado inicial es: (x->%d, y->%d)\n", x, y);
    x = x + y;
    printf("El segundo estado es: (x->%d, y->%d\n", x,y);
    y = y + y;
    printf("El estado final es: (x->%d, y->%d)\n", x,y);
}

void Ejercicio1c(void){
    printf("Ejercicio 1)c)\n");
    int x = Entero();
    int y = Entero();

    printf("El estado inicial es: (x->%d, y->%d)\n", x,y);
    y = y + y;
    printf("El segundo estado es: (x->%d, y->%d)\n", x,y);
    x = x + y;
    printf("El estado final es: (x->%d, y->%d)\n", x,y);
}

void Ejercicio1d(void){
    int x = Entero();
    int y = Entero();
    int temp = y;

    printf("El estado inicial es: (x->%d, y->%d)\n", x,y);
    y = y + y;
    x = x + temp;
    printf("El estado final es: (x->%d, y->%d)\n", x,y);
}

int main(void){
    Ejercicio1a();
    Ejercicio1b();
    Ejercicio1c();
    Ejercicio1d();

    return 0;
}
/*
Primera ejecucion
Ejercicio 1)a)
Ingrese un valor entero: 1
El estado inicial es: (x->1)
El segundo final es: (x->5)
Ejercicio 1)b)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
El estado inicial es: (x->2, y->5)
El segundo estado es: (x->7, y->5
El estado final es: (x->7, y->10)
Ejercicio 1)c)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
El estado inicial es: (x->2, y->5)
El segundo estado es: (x->2, y->10)
El estado final es: (x->12, y->10)

Segunda ejecucion
Ejercicio 1)a)
Ingrese un valor entero: 3
El estado inicial es: (x->3)
El segundo final es: (x->5)
Ejercicio 1)b)
Ingrese un valor entero: 12
Ingrese un valor entero: 31
El estado inicial es: (x->12, y->31)
El segundo estado es: (x->43, y->31
El estado final es: (x->43, y->62)
Ejercicio 1)c)
Ingrese un valor entero: 21
Ingrese un valor entero: 32
El estado inicial es: (x->21, y->32)
El segundo estado es: (x->21, y->64)
El estado final es: (x->85, y->64)

Tercera Ejecucion
Ejercicio 1)a)
Ingrese un valor entero: 3
El estado inicial es: (x->3)
El segundo final es: (x->5)
Ejercicio 1)b)
Ingrese un valor entero: 7
Ingrese un valor entero: 9
El estado inicial es: (x->7, y->9)
El segundo estado es: (x->16, y->9
El estado final es: (x->16, y->18)
Ejercicio 1)c)
Ingrese un valor entero: 3
Ingrese un valor entero: 5
El estado inicial es: (x->3, y->5)
El segundo estado es: (x->3, y->10)
El estado final es: (x->13, y->10)

*/