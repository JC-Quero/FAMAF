#include <stdio.h>
#include <limits.h>

#define N 6

void pedir_arreglo(int tam, int a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}


int minimo_pares(int tam, int a[]){
    int i = 0;
    int min = INT_MAX;
    while(i < tam){
        if (a[i] % 2 == 0 && a[i] < min){
            min = a[i];
        }
        i = i+1;
    }

    return min;
}

int minimo_impares(int tam, int a[]){
    int i = 0;
    int min = INT_MAX;

    while(i<tam){
        if((a[i] % 2 != 0) && (a[i] < min)){
            min = a[i];
        }
        i = i + 1;
    }

    return min;
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);
    int minPar = minimo_pares(N,a);
    int minImpar = minimo_impares(N,a);

    printf("El elemento par mas pequeno del arreglo es: %d\n", minPar);
    printf("El elemento impar mas pequeno del arreglo es: %d\n", minImpar);

    if (minPar < minImpar){
        printf("El minimo del arreglo es: %d", minPar);
    }else{
        printf("El minimo del arreglo es: %d", minImpar);
    }

    return 0;
}