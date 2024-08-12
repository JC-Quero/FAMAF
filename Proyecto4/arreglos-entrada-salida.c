#include <stdio.h>
#define N 3

void pedir_arreglo(int n_max, int a[]){
    int i = 0;
    while(i < n_max){
        printf("Ingrese los valores para el arreglo: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

void imprimir_arreglo(int n_max, int a[]){
    int i = 0;

    while (i < n_max){
        printf("Los valores de del arreglo son en la posicion: a[%d] = %d \n", i, a[i]);
        i = i+1;
    }
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);
    imprimir_arreglo(N,a);
    
    return 0;
}