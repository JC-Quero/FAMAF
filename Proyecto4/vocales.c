#include <stdio.h>
#include <stdbool.h>

char pedir_caracter(void) {
    char x;
    printf("Ingrese un caracter: ");
    scanf("%c", &x);
    return x;
}


bool es_vocal(char letra) {
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    char letra = pedir_caracter();
    bool resultado = es_vocal(letra);

    if (resultado) {
        printf("El caracter '%c' es una vocal.\n", letra);
    } else {
        printf("El caracter '%c' no es una vocal.\n", letra);
    }

    return 0;
}
