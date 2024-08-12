#include <stdio.h>

#define N 5

struct comp_t {
    int menores;
    int iguales;
    int mayores;
};

int pedir_entero(void){
    int x;
    printf("Ingrese su entero: ");
    scanf("%d", &x);
    return x;
}

void pedir_arreglo(int tam, int a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese el indice %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

struct comp_t cuantos(int tam, int a[], int elem){
    int i = 0;
    struct comp_t resultado;
    resultado.menores = 0;
    resultado.mayores = 0;
    resultado.iguales = 0;

    while (i<tam){
        if(a[i] < elem){
            resultado.menores = resultado.menores + 1;
        }else if(a[i] > elem){      
            resultado.mayores = resultado.mayores + 1;
        }else{
            resultado.iguales = resultado.iguales + 1;
        }

        i = i+1;
    }

    return resultado;
}

int main(void){
    int a[N];
    struct comp_t resultado;
    int elem = pedir_entero();
    pedir_arreglo(N,a);
    resultado = cuantos(N,a,elem);

    printf("Hay %d mayores, %d menores y %d iguales que el numero %d", resultado.mayores, resultado.menores, resultado.iguales, elem);

    return 0;
}

