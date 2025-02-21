#include "common.h"
#include "pieces.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <threads.h>

void empty_the_board(board_t*board)
{
    for (int i = 0; i < EIGHT; i++) {
        for (int j = 0; j < EIGHT; j++) {
            board->array[i][j] = calloc(1, sizeof(positions_t));
            board->array[i][j]->id = calloc(1, sizeof(id_of_board_t));
            board->array[i][j]->status = false;
        }
    }
}

void give_id_to_board(board_t* board)
{
    char* array_of_id = "ABCDEFGH";
    for (int i = 0; i < EIGHT; i++) {
        int id = 8;
        for (int j = 0; j < EIGHT; j++) {
            board->array[i][j]->id->first = array_of_id[j];
            board->array[i][j]->id->second = EIGHT - i;
            id--;
        }
    }
}
void populate_with_starting_pos(board_t *board)
{
    populate_pawns(board);
    populate_rooks(board);
    populate_horse(board);
    populate_bishop(board);
    populate_kings_and_queens(board);
    
}
board_t* create_board()
{
    board_t* board = calloc(1, sizeof(board_t));
    empty_the_board(board);
    give_id_to_board(board);
    populate_with_starting_pos(board);
    return board;
}
void print_board(board_t* board)
{   
    char* array_of_id = "ABCDEFGH";

    printf("  ");
    int k = 0;
    while (k < strlen(array_of_id)) {
        printf("   %c   ", array_of_id[k]);
        k++;
    }
    for (int i = 0; i < EIGHT; i++) {
        printf("\n");
        printf("%d", EIGHT- i);
        for (int j = 0; j < EIGHT; j++) {        
            printf("  ");
            // printf("%c%d", board->array[i][j]->id->first, board->array[i][j]->id->second);
            if (board->array[i][j]->status) {
                board->total_pieces++;
                printf("%s(%s)", board->array[i][j]->piece->name_of_piece, board->array[i][j]->piece->colour);
                continue;
            }
            printf("  X  ");
        }
    }   
    printf("\n");
    printf("total amont of pieces on the board %d \n", board->total_pieces);
}
void destroy_board(board_t *board)
{
    for (int i = 0; i < EIGHT; i++) {
        
        for (int j = 0; j < EIGHT; j++) {
            positions_t *current = board->array[i][j];
            if (current->piece) {
                // free(current->piece->name_of_piece);
                free(current->piece);
                free(current->id);
                free(current);
                continue;
            }
            free(current->id);
            free(current);
        }
    }
    free(board->array);
}

void out_of_bounds(board_t* board, move_t * move)
{

}

void valid_move(board_t* board, move_t *move)
{

}
void check(board_t* board, move_t* move)
{

}
void move(board_t* board)
{
    move_t *to_move = calloc(1, sizeof(move_t));
    // Get user input
    out_of_bounds(board, to_move);
    valid_move(board, to_move);
    check(board, to_move);
    
}
int main(void)
{
    board_t *board = create_board();
    print_board(board);
    move(board);

    destroy_board(board);
    return 0;
}