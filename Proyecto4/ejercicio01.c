#include <stdio.h>
#include <assert.h>

int cantidad_hola(void){
    int x;
    printf("Ingrese un numero n: ");
    scanf("%d", &x);
    return x;
}

void hola_hasta(int n){
    assert(n>0);
    while(n>0){
        printf("Hola\n");
        n--;
    }
}

int main (void){
    int n = cantidad_hola();
    hola_hasta(n);
    return 0;
}