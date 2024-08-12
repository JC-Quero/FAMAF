#include <stdio.h>

int pedir_entero(void){
    int x;
    printf("Ingrese un valor de x: \n");
    scanf("%d",&x);
    return x;
}

void imprimir_entero(int x){
    printf("Su numero entero es: %d", x);
}

int main(void){
    int y = pedir_entero();
    imprimir_entero(y);
}