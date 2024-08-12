#include <stdio.h>
#include <stdbool.h>

void Ejercicio1h(void){
    int i = 0;
    int es = 0;

    printf("Ingrese un valor para i :");
    scanf("%d", &i);

    printf("El estado inicial de i es: %d\n", i);

    while(i!= 0){
        es++;
        printf("o1 %d (i = %d)\n", es, i);
        i = i - 1;
        printf("o2 %d (i = %d)\n", es, i);
    }
    printf("o3 (i = %d)\n", i);


}

void Ejercicio1i(void){
    int i = 0;
    int es = 0;

    printf("Ingrese un valor para i : ");
    scanf("%d", &i);

    printf("El estado inicial de i es: %d\n", i);

    while(i!= 0){
        es++;
        printf("o1 %d (i = %d)\n", es, i);
        i = 0;
        printf("o2 %d (i = %d)\n", es, i);
    }
    printf("o3 (i = %d)\n", i);

}

int main(void){
   Ejercicio1h();
   Ejercicio1i();

   return 0;
}

/*
Resumen
Ejercicio1h: Decrementa i en cada iteración del ciclo while hasta que i sea 0.
Ejercicio1i: Asigna i a 0 dentro del ciclo while, lo que hace que el ciclo se ejecute solo una vez.
Ambos programas imprimen el estado de i en diferentes puntos del ciclo para mostrar cómo cambia su valor.


PS E:\FAMAF\Proyecto3> gcc -Wall -Wextra -std=c99 .\ciclos.c -o ej5
PS E:\FAMAF\Proyecto3> .\ej5.exe
Ingrese un valor para i :4
El estado inicial de i es: 4
o1 1 (i = 4)
o2 1 (i = 3)
o1 2 (i = 3)
o2 2 (i = 2)
o1 3 (i = 2)
o2 3 (i = 1)
o1 4 (i = 1)
o2 4 (i = 0)
o3 (i = 0)
Ingrese un valor para i : 400
El estado inicial de i es: 400
o1 1 (i = 400)
o2 1 (i = 0)
o3 (i = 0)

*/