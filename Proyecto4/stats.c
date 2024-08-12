#include <stdio.h>
#include <limits.h>
#include <float.h>

#define N 5

struct datos_t {
float maximo;
float minimo;
float promedio;
};

void pedir_arreglo(int tam, float a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%f", &a[i]);
        i = i+1;
    }
}

struct datos_t stats(int tam, float a[]){
    int i = 0;
    struct datos_t res;
    float min = FLT_MAX;
    float max = FLT_MIN;
    float pro = 0;

    while (i<tam){
        if(a[i] > max){
            max = a[i];
        }else if(a[i] < min){
            min = a[i];
        }

        pro = pro + a[i];
        i = i+1;
    }

    res.maximo = max;
    res.minimo = min;
    res.promedio = (pro/tam);

    return res;
    
}

int main (void){
    struct datos_t res;
    float a[N];
    pedir_arreglo(N,a);

    res = stats(N,a);

    printf("El maximo es %f , el minimo es %f y el promedio es %f", res.maximo, res.minimo, res.promedio);

    return 0;
}