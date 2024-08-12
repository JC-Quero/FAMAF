#include <stdio.h>
#include <assert.h>

int pedir_entero(void){
    int x;
    printf("Ingrese el entero:");
    scanf("%d", &x);
    
    return x;
}

void asig_mul(int x, int y){
    int X = x;
    int Y = y;

    assert(x == X && y == Y);

    x = X + 1; 
    y = X + Y;

    assert( x == X + 1 && y == X + Y );
    printf("x = %d, y = %d", x,y);

}

int main (void){
    int x = pedir_entero();
    int y = pedir_entero();

    asig_mul(x,y);
    return 0;
}