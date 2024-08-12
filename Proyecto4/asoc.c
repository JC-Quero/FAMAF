#include <stdio.h>
#include <stdbool.h>

#define N 5

typedef char clave_t;
typedef int valor_t;

struct asoc {
clave_t clave;
valor_t valor;
};

void pedir_arreglo(int tam, struct asoc a[]){
    int i = 0;
    while(i < tam){
        printf("Ingrese clave y valor para  a[%d]: ", i);
        scanf(" %c", &a[i].clave);
        scanf("%d", &a[i].valor);
        i = i+1;
    }
}

char pedir_clave(void){
    char x;
    printf("Ingrese su otra clave para ver si esta: ");
    scanf(" %c", &x);
    return x;
}

bool asoc_existe(int tam, struct asoc a[], clave_t c){
    int i = 0;
    while (i < tam){
        if(a[i].clave == c){
            return true;
        }
        i = i+1;
    }

    return false;

}

int main(void){
    struct asoc a[N];
    pedir_arreglo(N,a);
    clave_t clave = pedir_clave();
    bool resul = asoc_existe(N,a,clave);

    if (resul){
        printf("La calve %c esta en el arreglo\n", clave);
    }else{
        printf("La clave %c no esta en el arreglo\n", clave);
    }

    return 0;
}