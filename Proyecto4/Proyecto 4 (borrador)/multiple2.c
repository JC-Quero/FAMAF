#include <stdio.h>
#include <assert.h>

int pedir_entero(void){
    int x;
    printf("Ingrese el entero:");
    scanf("%d", &x);
    
    return x;
}

void asig_mul(int x, int y, int z){
    int X = x;
    int Y = y;
    int Z = z;

    assert(x == X && y == Y && z == Z);

    x = Y; 
    y = X + Y + Z;
    z = Y + X;

    assert( x == Y && y == X + Y + Z && z == Y + X );
    printf("x = %d, y = %d z = %d", x,y,z);

}

int main (void){
    int x = pedir_entero();
    int y = pedir_entero();
    int z = pedir_entero();

    asig_mul(x,y,z);
    return 0;
}