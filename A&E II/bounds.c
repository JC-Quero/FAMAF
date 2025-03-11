#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define ARRAY_SIZE 4

struct bound_data
{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where
};

struct bound_data check_bound(int value, int arr[], unsigned int length){
    struct bound_data res;
    unsigned int i = 0;
    res.is_lowerbound = true;
    res.is_upperbound = true;
    res.exists = false;
    res.where = 0;

    while(i<length){
        res.is_upperbound = res.is_upperbound && (value >= arr[i]);
        res.is_lowerbound = res.is_lowerbound && (value <= arr[i]);

        if (value == arr[i]){
            res.exists = true;
            res.where = i;
        }
        i++;
    }
    return res;
}

void pedir_arreglo(int tam, int a[]){
    int i = 0;

    while (i<tam){
        printf("Ingrese valor para la posicion %d: ", i);
        scanf("%d", &a[i]);
        assert((INT_MIN < a[i]) && (a[i] < INT_MAX));
        i++;
    }
}

int pedir_entero(){ 
    int x;
    printf("Ingrese un numero para comparar: ");
    scanf("%d", &x);
    return x;
}

int main(void){
    int a[ARRAY_SIZE];
    pedir_arreglo(ARRAY_SIZE,a);
    int value;
    value = pedir_entero();
    struct bound_data res = check_bound(value,a,ARRAY_SIZE);

    if (res.exists && res.is_lowerbound){
        printf("%d es un minimo, con posicion: %u \n", value, res.where);
    }else if(res.is_lowerbound){
        printf("%d es una cota inferior. \n", value);
    }

    if (res.exists && res.is_upperbound){
        printf("%d es un maximo, con posicion: %u \n", value, res.where);
    }else if(res.is_upperbound){
        printf("%d es una cota superior. \n", value);
    }

    if(!res.exists && !res.is_lowerbound && !res.is_upperbound){
        printf("no existe en el arreglo. \n");
    }

    return 0;    
}
