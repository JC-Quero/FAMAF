#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    assert(k < length);
    int elem = 0;
    
    int izq = 0, der = length - 1;
    int piv_pos = partition(a, izq, der);
    /*
        printf("ANTES DE COMENZAR\n");
        printf("left es:%d ", izq);
        printf("rgt es:%d ", der);
        printf("ppiv es:%d y su valor es:%d\n", piv_pos,a[piv_pos]);

        printf("------------------------\n");

    */

    while (piv_pos != k) {
       /* 
            printf("left es:%d ", izq);
            printf("rgt es:%d ", der);
            printf("ppiv es:%d\n", piv_pos);

            printf("------------------------\n");
        */

        if (piv_pos > k) {
            der = piv_pos - 1;
        } else{
            izq = piv_pos + 1;
        } 
        piv_pos = partition(a,izq,der);
    }

    elem = a[k];
    return elem;
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
