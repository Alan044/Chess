#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define EIGHT 8
typedef struct pieces pieces_t;
typedef struct board board_t;
typedef struct positions positions_t;
typedef struct id_of_board id_of_board_t;

struct id_of_board {
    char first;
    int second;
};
struct positions {
    pieces_t* piece;
    bool status;
    id_of_board_t* id;
};

struct pieces {
    char* name_of_piece;
    int points;
};


struct board {
    positions_t *array[EIGHT][EIGHT];
};

void empty_the_board(board_t*board)
{
    for (int i = 0; i < EIGHT; i++) {
        for (int j = 0; j < EIGHT; j++) {
            board->array[i][j] = calloc(1, sizeof(positions_t*));
            board->array[i][j]->id = calloc(1, sizeof(id_of_board_t*));
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
void populate_pawns(board_t *board)
{
    for (int j = 0; j < EIGHT; j++) {
        pieces_t* piece = calloc(1, sizeof(pieces_t));
        piece->name_of_piece = calloc(1, sizeof(char*));
        piece->name_of_piece = "P";
        piece->points = 1;
        board->array[1][j]->piece = piece;
        board->array[1][j]->status = true; 
    }
    for (int j = 0; j < EIGHT; j++) {
        pieces_t* piece = calloc(1, sizeof(pieces_t));
        piece->name_of_piece = calloc(1, sizeof(char*));
        piece->name_of_piece = "P";
        piece->points = 1;
        board->array[6][j]->piece = piece;
        board->array[6][j]->status = true; 
    }
}

void populate_rooks(board_t *board)
{  
    
    pieces_t* rook = calloc(1, sizeof(pieces_t));
    rook->name_of_piece = calloc(1, sizeof(char*));
    rook->name_of_piece = "R";
    rook->points = 5;
    board->array[0][0]->piece = rook;
    board->array[0][0]->status = true;

    board->array[0][7]->piece = rook; 
    board->array[0][7]->status = true;

    board->array[7][7]->piece = rook;
    board->array[7][7]->status = true;

    board->array[7][0]->piece = rook;
    board->array[7][0]->status = true;

}
void populate_horse(board_t *board)
{
    pieces_t* horse = calloc(1, sizeof(pieces_t));
    horse->name_of_piece = calloc(1, sizeof(char*));
    horse->name_of_piece = "H";
    horse->points = 3;
    board->array[0][1]->piece = horse;
    board->array[0][1]->status = true;

    board->array[0][6]->piece = horse;
    board->array[0][6]->status = true;

    board->array[7][6]->piece = horse;
    board->array[7][6]->status = true;

    board->array[7][1]->piece = horse;
    board->array[7][1]->status = true;
    
}
void populate_bishop(board_t *board)
{
    pieces_t* bishop = calloc(1, sizeof(pieces_t));
    bishop->name_of_piece = calloc(1, sizeof(char*));
    bishop->name_of_piece = "B";
    bishop->points = 3;
    board->array[0][2]->piece = bishop;
    board->array[0][2]->status = true;

    board->array[0][5]->piece = bishop;
    board->array[0][5]->status = true;

    board->array[7][5]->piece = bishop;
    board->array[7][5]->status = true;

    board->array[7][2]->piece = bishop;
    board->array[7][2]->status = true;
}

void populate_kings_and_queens(board_t *board)
{
    pieces_t* Queen = calloc(1, sizeof(pieces_t));
    Queen->name_of_piece = calloc(1, sizeof(char*));
    Queen->name_of_piece = "Q";
    Queen->points = 9;
    board->array[0][3]->piece = Queen; 
    board->array[0][3]->status = true; 
    board->array[7][3]->piece = Queen; 
    board->array[7][3]->status = true;
    pieces_t* King = calloc(1, sizeof(pieces_t));
    King->name_of_piece = calloc(1, sizeof(char*));
    King->name_of_piece = "K";
    King->points = 0;
    board->array[0][4]->piece = King; 
    board->array[0][4]->status = true; 
    board->array[7][4]->piece = King;
    board->array[7][4]->status = true;

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
    for (int i = 0; i < EIGHT; i++) {
        printf("\n");        
        for (int j = 0; j < EIGHT; j++) {
            printf("  ");
            // printf("%c%d", board->array[i][j]->id->first, board->array[i][j]->id->second);
            if (board->array[i][j]->piece) {
                printf("%d", board->array[i][j]->status);
                continue;
            }
            printf("X");
        }
    }   
    printf("\n");
}

int main(void)
{
    board_t *board = create_board();
    print_board(board);
    return 0;
}