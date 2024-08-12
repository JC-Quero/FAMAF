#include <stdio.h>
#include <assert.h>

int pedir_entero(void){
    int x;
    printf("Ingrese su valor: ");
    scanf("%d", &x);
    return x;
}

int valor_minimo(int x, int y){
    if (x>y){
        return x;
    }
    else{
        return y;
    }
}

int main(void){
    int x = pedir_entero();
    int y = pedir_entero();
    int minimo = valor_minimo(x,y);
    printf("%d\n", minimo);

    return 0;
} 