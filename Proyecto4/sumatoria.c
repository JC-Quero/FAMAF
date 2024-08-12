#include <stdio.h>
#define N 3


void pedir_arreglo(int tam , int a[]){
    int i =0;

    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}


int sumatoria(int tam, int a[]){
    int i = 0;
    int suma = 0;
    while (i < tam){
        suma = suma + a[i];
        i = i + 1;
    }

    return suma;
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);
    int suma = sumatoria(N,a);
    printf("La suma es: %d", suma);

    return 0;
}