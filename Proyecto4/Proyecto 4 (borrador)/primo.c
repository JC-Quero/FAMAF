#include <stdio.h>
#include <stdbool.h>

int pedir_entero(void){
    int x;
    printf("Ingrese un valor no negativo: ");
    scanf("%d", &x);

    while (x < 0){
        printf("Ingrese otro valor: ");
        scanf("%d", &x);
    }

    return x;
}

int es_primo(int n){
    int i = 2;
    bool resul = true;

    while (i < n && resul){
        resul = resul && !(n % i == 0);
        i = i +1;
    }

    return resul;
}

int nesimo_primo(int n){
    int x=1;
    int primos = 0;

    while (primos != n){
        x = x +1;
        if(es_primo(x)){
            primos = primos + 1;
        }
    }
    return x;
}

int main(void){
    int n = pedir_entero();
    int resul = nesimo_primo(n);
    printf("El primo numero %d es : %d", n , resul);

    return 0;

}