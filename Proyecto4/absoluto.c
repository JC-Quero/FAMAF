#include <stdio.h>
#include <assert.h>

int pedir_entero(void){
    int x;
    printf("Ingrese el valor:");
    scanf("%d", &x);

    return x;
}

int absoluto(int x){

    if (x>0){
        return x;
    }
    else {
        return (-x);
    }
}

int main(void){
    int x = pedir_entero();
    int val_abs = absoluto(x);
    printf("el valor absoluto del numero ingresado es: \n %d", val_abs);
    return 0;
}