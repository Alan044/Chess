#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EIGHT 8
typedef struct pieces pieces_t;
typedef struct board board_t;

struct pieces {
    char* name_of_piece;
    bool status;
    int points;
};


struct board {
    pieces_t ***array;
};

board_t* create_board()
{
    board_t* board = calloc(1, sizeof(board_t));

    board->array = calloc(64, sizeof(pieces_t*));

    for (int i = 0; i < EIGHT; i++) {
        
        for (int j = 0; j < EIGHT; j++) {
            pieces_t *piece = calloc(1, sizeof(pieces_t));
            piece->name_of_piece = strdup("test");
            piece->points = 8;
            piece->status = false;
            board->array[i][j] = calloc(1, sizeof(pieces_t*));
        }
    }

    return board;
}



int main(void)
{
    board_t *board = create_board();
    printf("Hello World \n");
    return 0;
}