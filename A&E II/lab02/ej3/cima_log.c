#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

 bool es_cima(int a[], int i, int lenght){
    bool b = (i == 0 || a[i] > a[i-1]) && (i == lenght - 1 || a[i] > a[i+1]);
    return b;
}

bool izq_cima(int a[], int i){
    bool b = (i > 0 && a[i-1] > a[i]);
    return b;
}

bool der_cima(int a[], int i, int lenght){
    bool b = (i < lenght - 1 && a[i] < a[i+1]);
    return b;
}

int cima_rec(int a[],int lft, int rgt, int lenght){
    int k;
    int mid = (lft+rgt)/2;

    if(es_cima(a,mid,lenght)){

        k = mid;

    }else if (izq_cima(a,mid)){

        k = cima_rec(a,lft,mid-1,lenght);

    }else if (der_cima(a,mid,lenght)){
        
        k = cima_rec(a,mid+1,rgt,lenght);

    }
    
    return k;

}


int cima_log(int a[], int length) {
    int k = cima_rec(a,0,length-1,length);
    return k;
}


