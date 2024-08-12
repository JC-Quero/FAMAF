#include <stdio.h>
#include <assert.h>
#define N 5

void pedir_arreglo(int tam, int a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

int pedirEntero(int tam){
    int m;
    printf("Ingrese un indice para intercambiar, del 0 al  %d", (tam - 1));
    scanf("%d", &m);
    return m;
}

void imprimir_arreglo(int tam, int a[]){
    int i = 0;

    while (i < tam){
        printf("Los valores de del arreglo son en la posicion: a[%d] = %d \n", i, a[i]);
        i = i+1;
    }
}

void intercambiar(int tam, int a[], int i, int j){
    int ax = a[i];
    assert(i < tam && j < tam && i != j);
    a[i] = a[j];
    a[j] = ax;
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);
    int i = pedirEntero(N);
    int j = pedirEntero(N);
    intercambiar(N, a, i, j);
    imprimir_arreglo(N,a);
    
    return 0;
}