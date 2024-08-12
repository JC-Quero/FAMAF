#include <stdio.h>
#include <stdbool.h>

// Prototipo de la función pedir_booleano
bool pedir_booleano(void);

// Prototipo de la función imprimir_booleano
void imprimir_booleano(bool x);

int main() {
    // Pedir al usuario que ingrese un booleano y guardarlo en la variable 'b'
    bool b = pedir_booleano();

    // Imprimir el booleano ingresado por el usuario
    imprimir_booleano(b);

    return 0;
}

// Definición de la función pedir_booleano
bool pedir_booleano(void) {
    bool booleano;
    int entrada;
    printf("Ingrese un valor booleano (0 para falso, 1 para verdadero): ");
    scanf("%d", &entrada);
    
    // Convertir el entero ingresado a tipo bool
    booleano = (entrada != 0);
    
    return booleano;
}

// Definición de la función imprimir_booleano
void imprimir_booleano(bool x) {
    if (x) {
        printf("Verdadero\n");
    } else {
        printf("Falso\n");
    }
}
