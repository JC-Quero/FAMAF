#include <stdio.h> 
#include <assert.h>


struct div_t{
    int cociente;
    int resto;
};

int pedir_entero(void){
    int x;
    printf("Ingrese su entero: ");
    scanf("%d", &x);
    return x;
}

struct div_t division(int x, int y){
    struct div_t resultado;
    assert(x >= 0 && y > 0);

    resultado.cociente = x / y;
    resultado.resto = x % y;

    return resultado;
}

int main(void){
    struct div_t div;
    int x = pedir_entero();
    int y = pedir_entero();
    div = division(x, y);

    printf("El cociente es = %d y el resto es = %d \n", div.cociente, div.resto);

    return 0;

}