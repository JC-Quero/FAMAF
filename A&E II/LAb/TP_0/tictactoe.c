#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

//Define el valor 8 (3 * 3 - 1), que representa la última celda del tablero, numerada del 0 al 8.
#define CELL_MAX (3 * 3 - 1)

//---------------------------------------------------------------------------------

//Imprime una línea separadora en la consola.
//Se usa en print_board() para dibujar el tablero.

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

//---------------------------------
//Imprime el tablero de juego, mostrando las posiciones numéricas de cada celda junto con su contenido ('X', 'O' o '-' si está vacía).
//Usa print_sep(3) para dibujar las líneas divisorias.

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}
//-----------------------------
//Determina si hay un ganador, pero aún no está implementada.
//Debería revisar si hay 3 símbolos iguales en una fila, columna o diagonal.
//No implementado

char get_winner(char board[3][3])
{
    char winner = '-';
    //
    // TODO: COMPLETAR
    //
    return winner;
}

//----------------------------------------------------
//Comprueba si quedan celdas libres en el tablero, pero no está implementada.
//Debería recorrer board y devolver true si hay al menos un '-'.
//No implementado

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    //
    // TODO: COMPLETAR
    //
    return free_cell;
}


//-----------------------------------------


int main(void)
{
    //Muestra un mensaje inicial indicando que el juego está incompleto.
    printf("TicTacToe [InCoMpLeTo :'(]\n");
    

    //Crea una matriz 3x3 inicializada con '-' para representar un tablero vacío.
    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };


    //turn: Indica de quién es el turno ('X' o 'O').
    //winner: Guarda el ganador ('X', 'O' o '-' si aún no hay).
    //cell: Almacena la celda seleccionada por el usuario.

    char turn = 'X';
    char winner = '-';
    int cell = 0;

    //El bucle se ejecuta mientras no haya un ganador y haya celdas libres.
    while (winner == '-' && has_free_cell(board)) {
        //se muestra el tablero
        print_board(board);
        //se muestra el mensaje de turno
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        //Si el usuario ingresa un número fuera del rango, se muestra un mensaje de error
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        //Se verifica si la celda ingresada es valida
        //convierte el numero ingresado en coordenadas de una matriz
        //Verifica si la celda esta vacia
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }

    //Muestra el tablero final.
    //Muestra el resultado del juego:
        //Si winner == '-', hay un empate.
        //Si winner es 'X' o 'O', imprime al ganador.

    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
