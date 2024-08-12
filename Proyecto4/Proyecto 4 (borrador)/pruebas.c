#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define N 5

bool esta_en_posicion(int a[], int tam, int v){
    int i = 0;
    bool esta = false;

    while (i<tam){
        if(a[i] == v){
            esta = true;
            break;
        }else{
            esta = false;
        }
        i++;
    }

    return esta;
}

int main(void){
    int a[N];
    int v;

    //pedimos valor de v
    printf("Ingrese el valor de v: ");
    scanf("%d", &v);

    //pedimos arreglo
    int i = 0;

    while(i<N){
        printf("Ingrese el valor del arreglo a[%d]: ", i);
        scanf("%d", &a[i]);
        i++;
    }    

    //Llamamos
    bool esta = esta_en_posicion(a, N, v);

    //Mostramos
    if(esta == true){
        printf("El valor %d esta en la posicion %d \n", v, i);
    }else{
        printf("El valor %d no esta en la posicion \n", v, i);
    }

    return 0;
}