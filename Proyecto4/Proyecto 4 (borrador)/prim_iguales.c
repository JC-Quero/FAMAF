#include <stdio.h>

#define N 5

void pedir_arreglo(int tam, int a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

void imprimir_arreglo(int tam, int a[]){
    int i = 0;
    while (i < tam){
        printf("Los valores de del arreglo son en la posicion: a[%d] = %d \n", i, a[i]);
        i = i+1;
    }
}

int prim_iguales(int tam, int a[]){
    int i = 1;
    while(i < tam){
        if(a[0] != a[i]){
            imprimir_arreglo(i, a);
            return i;
        }
        i = i + 1;
    }
    return i;
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);
    int prim = prim_iguales(N,a);
    printf("El tramo mas largo del arreglo es %d\n", prim);

    return 0;
}