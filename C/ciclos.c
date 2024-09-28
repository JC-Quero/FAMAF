#include <stdio.h>
#include <stdbool.h>

void ciclo_1a(void){
    int es = 0;
    int i;

    printf("Entramos al Ciclo_1a\n\n");

    printf("Ingrese un valor para su estado: \n");
    scanf("%d", &i);

    printf("El estado inicial es: (i->%d)\n", i);

    while (i!= 0){
      es++;
      printf("o1 %d (i = %d)\n", es,i);
      i = i - 1;
      printf("o2 %d (i -> %d)\n",es,i);
    }

    printf("o3 (i->%d)\n\n",i);
}

void ciclo_1b(void){
    int i;
    int es = 0;

    printf("Entramos al Ciclo_1b\n\n");


    printf("Ingrese un valor para su estado: \n");
    scanf("%d", &i);

    printf("El estado inicial es: (i->%d)\n", i);

    while(i!=0){
        es++;
        printf("o1 %d (i = %d)\n", es,i);
        i = 0;
        printf("o2 %d (i -> %d)\n",es,i);
    }
    printf("o3 (i->%d)\n\n",i);
}

void ciclo_1c(void){
    int r;
    int es = 0;

    printf("Entramos al Ciclo_1c\n\n");


    printf("Ingrese el valor de r para su estado inicial: \n");
    scanf("%d", &r);

    printf("El estado inical es: %d\n", r);

    while(r!=0){
        es++;
        printf("o%d y el estado r es: %d\n",es,r);

            if(r<0){
                printf("o%d y el estado r es: %d\n",es,r);
                r++;
                printf("o%d y el estado r es: %d\n",es,r);

            }else if(r>0){
                printf("o%d y el estado r es: %d\n",es,r);
                r = r - 1;
                printf("o%d y el estado r es: %d\n",es,r);
            }
        printf("o%d y el estado r es: %d\n",es,r);
    }
    printf("o%d y el estado r es: %d\n",es,r);
}


//Laboratorio 8

void Lab_8a(void){
    int x,y,z;
    
    printf("Ingrese valor para estado x: \n");
    scanf("%d", &x);

    printf("Ingrese valor para estado y: \n");
    scanf("%d", &y);

    printf("Ingrese valor para estado z: \n");
    scanf("%d", &z);

    printf("El estado inicial es de: (x->%d, y->%d, z->%d)\n", x,y,z);

    z = 0;

    while(x>=y){
        x = x-y;
        z++;

        printf("o1 %d (x->%d, y->%d, z->%d)\n",z,x,y,z);
    }

    /*
    Ejecucion
    Ingrese valor para estado x:
    13
    Ingrese valor para estado y:
    3
    Ingrese valor para estado z:
    0
    El estado incial es de: (x->13, y->3, z->0)
    o1 1 (x->10, y->3, z->1)
    o1 2 (x->7, y->3, z->2)
    o1 3 (x->4, y->3, z->3)
    o1 4 (x->1, y->3, z->4)
    
    */
}

void Lab_8b(void){
    int x,i;
    bool res;

    printf("Ingrese el valor de su estado x: ");
    scanf("%d", &x);

    printf("Ingrese el valor de su estado i: ");
    scanf("%d", &i);

    i=2;
    res=true;

    printf("El valor inicial de los estados es: (x->%d, i->%d, res->%d)\n",x,i,res);

   

    while((i<x)&& res){
        res = res && (x%i !=0);
        i++;

        printf("o1 %d, (x->%d, i->%d, res->%d)\n", i,x,i,res);
    }
    /*
    ejecucion 
    Ingrese el valor de su estado x: 5
    Ingrese el valor de su estado i: 0
    El valor inicial de los estados es: (x->5, i->2, res->1)
    o1 3, (x->5, i->3, res->1)
    o1 4, (x->5, i->4, res->1)
    o1 5, (x->5, i->5, res->1)
    
    */

}

int main(void){
    ciclo_1a();
    ciclo_1b();
    ciclo_1c();

    Lab_8a();
    Lab_8b();
    return 0;
}