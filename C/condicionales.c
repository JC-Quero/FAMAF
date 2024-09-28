#include <stdio.h>

int Entero(void){
    int x;
    printf("Ingrese un numero entero: ");
    scanf("%d", &x);
    return x;
}

void condi_1a(void){
    int x = Entero();
    int y = Entero();

    printf("El estado inicial es: (x->%d, y->%d)\n", x,y);

    if(x>=y){
        printf("(x>=y)\n");

        printf("El primer estado es: (x->%d, y->%d)\n", x,y);
        x = 0;
        printf("El segundo estado es: (x->%d, y->%d)\n",x,y);
    }else if(x<=y){
        printf("El primer inicial es: (x->%d, y->%d)\n",x,y);
        x = 2;
        printf("El segundo estado es: (x->%d, y->%d)\n",x,y);
    }

    printf("El estado final es: (x->%d, y->%d)\n\n",x,y);

}

//laboratorio 5

void Lab_5(void){

    printf("Laboratorio 5\n\n");
    int x = Entero();
    int y = Entero();
    int z = Entero();
    int m = Entero();

    printf("El estado inicial es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);

    if(x<y){
        m = x;
        printf("El primer estado es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);
    }else if(x>=y){
        m = y;
        printf("El segundo estado es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);
    }

    printf("El primer estado es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);

    if(m<z){
    }else if(m>=z){
        m = z;
        printf("El segundo estado es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);
    }

    printf("El estado final es: (x->%d, y->%d, z->%d, m->%d)\n",x,y,z,m);

}

int main(void){
    condi_1a();
    Lab_5();
    return 0;
}

/*
Primera ejecucion(Primer estado dado en practico)
Ingrese un numero entero: 3
Ingrese un numero entero: 1
El estado inicial es: (x->3, y->1)
(x>=y)
El primer estado es: (x->3, y->1)
El segundo estado es: (x->0, y->1)
El estado final es: (x->0, y->1)

Segunda Ejecucion(segundo estado dados en practico)
Ingrese un numero entero: -100
Ingrese un numero entero: 1
El estado inicial es: (x->-100, y->1)
El primer inicial es: (x->-100, y->1)
El segundo estado es: (x->2, y->1)
El estado final es: (x->2, y->1)

Ejecucion programa Lab_5 (con estados dados)

Laboratorio 5

Ingrese un numero entero: 5
Ingrese un numero entero: 4
Ingrese un numero entero: 8
Ingrese un numero entero: 0
El estado inicial es: (x->5, y->4, z->8, m->0)
El segundo estado es: (x->5, y->4, z->8, m->4)
El primer estado es: (x->5, y->4, z->8, m->4)
El estado final es: (x->5, y->4, z->8, m->4)

Segunda Ejecucion Lab_5 (Estados random)
Laboratorio 5

Ingrese un numero entero: 1
Ingrese un numero entero: 2
Ingrese un numero entero: 3
Ingrese un numero entero: 4
El estado inicial es: (x->1, y->2, z->3, m->4)
El primer estado es: (x->1, y->2, z->3, m->1)
El primer estado es: (x->1, y->2, z->3, m->1)
El estado final es: (x->1, y->2, z->3, m->1)

*/