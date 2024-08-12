#include <stdio.h>
#include <assert.h>

int pedir_numero(){
    int n;
    printf("Ingrese su numero: ");
    scanf("%d", &n);
    return n;
}

int suma_hasta(int n){
    int x = 0;
    assert(n>=0);

    while(n>=0){
        x = x + n;
        n--;
    }

    return x;
}

int main(void){
    int n = pedir_numero();
    int x = suma_hasta(n);
    printf("La suma de los primeros %d naturales es: %d\n", n, x);
    return 0;
}