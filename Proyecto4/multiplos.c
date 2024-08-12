#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define N 3

void pedir_arreglo(int tam, int a[]){
    int i= 0;
    while(i < tam){
        printf("Ingrese el indice del arreglo %d: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

bool todos_pares(int tam, int a[]){
    int i = 0;    
    while(i < tam){
        if(a[i] % 2 != 0){
            return false;
        }
        i = i + 1;
    }
    return true;
}

bool existe_multiplo(int m, int tam, int a[]){
    int i = 0;
    while(i < tam ){
        if (a[i] % m == 0){
            return true;
        }
        i = i+1;
    }
    return false;
}

int main(void){
    int a[N];
    pedir_arreglo(N,a);

    int opcion;

    printf("Elija la funcion a ejecutar:\n");
    printf("1. verificar si todos los elementos son pares\n");
    printf("2. Verificar si existe un multiplo de un numero dado\n");
    scanf("%d", &opcion);

    assert(opcion == 1 || opcion == 2);
    if (opcion == 1){
        if (todos_pares(N,a)){
            printf("True, Todos los elementos del arreglo son pares\n");
        }else{
            printf("False, No todos los elementos del arreglo son pares\n");
        }
    }else if(opcion == 2){
        int m;
        printf("Ingrese el valor de m: ");
        scanf("%d", &m);
        if(existe_multiplo(m, N, a)){
            printf("True, Existe un multiplo de %d en el arreglo\n", m);
        }else{
            printf("False, No existe un multiplo de %d en el arreglo \n", m);
        }
    }

    return 0;
}
