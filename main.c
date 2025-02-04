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
    char* colour;
};


struct board {
    positions_t *array[EIGHT][EIGHT];
    int total_pieces;
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
        board->array[1][j]->piece->colour = ("bl"); 
    }
    for (int j = 0; j < EIGHT; j++) {
        pieces_t* piece = calloc(1, sizeof(pieces_t));
        piece->name_of_piece = calloc(1, sizeof(char*));
        piece->name_of_piece = "P";
        piece->points = 1;
        board->array[6][j]->piece = piece;
        board->array[6][j]->status = true; 
        board->array[6][j]->piece->colour = ("wh"); 
    }
}

void populate_rooks(board_t *board)
{  
    
    pieces_t* rook_tl = calloc(1, sizeof(pieces_t));
    rook_tl->name_of_piece = calloc(1, sizeof(char*));
    rook_tl->name_of_piece = "R";
    rook_tl->points = 5;
    board->array[0][0]->piece = rook_tl;
    board->array[0][0]->status = true;
    board->array[0][0]->piece->colour = "bl";

    pieces_t* rook_tr = calloc(1, sizeof(pieces_t));
    rook_tr->name_of_piece = calloc(1, sizeof(char*));
    rook_tr->name_of_piece = "R";
    rook_tr->points = 5;
    board->array[0][7]->piece = rook_tr; 
    board->array[0][7]->status = true;
    board->array[0][7]->piece->colour = "bl";

    pieces_t* rook_dl = calloc(1, sizeof(pieces_t));
    rook_dl->name_of_piece = calloc(1, sizeof(char*));
    rook_dl->name_of_piece = "R";
    rook_dl->points = 5;
    board->array[7][7]->piece = rook_dl;
    board->array[7][7]->status = true;
    board->array[7][7]->piece->colour = "wh";

    pieces_t* rook_dr = calloc(1, sizeof(pieces_t));
    rook_dr->name_of_piece = calloc(1, sizeof(char*));
    rook_dr->name_of_piece = "R";
    rook_dr->points = 5;
    board->array[7][0]->piece = rook_dr;
    board->array[7][0]->status = true;
    board->array[7][0]->piece->colour = "wh";

}
void populate_horse(board_t *board)
{
    pieces_t* horse_tl = calloc(1, sizeof(pieces_t));
    horse_tl->name_of_piece = calloc(1, sizeof(char*));
    horse_tl->name_of_piece = "H";
    horse_tl->points = 3;
    board->array[0][1]->status = true;
    board->array[0][1]->piece = horse_tl;
    board->array[0][1]->piece->colour = "bl";

    pieces_t* horse_tr = calloc(1, sizeof(pieces_t));
    horse_tr->name_of_piece = calloc(1, sizeof(char*));
    horse_tr->name_of_piece = "H";
    horse_tr->points = 3;
    board->array[0][6]->status = true;
    board->array[0][6]->piece = horse_tr;
    board->array[0][6]->piece->colour = "bl";

    pieces_t* horse_dl = calloc(1, sizeof(pieces_t));
    horse_dl->name_of_piece = calloc(1, sizeof(char*));
    horse_dl->name_of_piece = "H";
    horse_dl->points = 3;
    board->array[7][6]->status = true;
    board->array[7][6]->piece = horse_dl;
    board->array[7][6]->piece->colour = "wh";

    pieces_t* horse_dr = calloc(1, sizeof(pieces_t));
    horse_dr->name_of_piece = calloc(1, sizeof(char*));
    horse_dr->name_of_piece = "H";
    horse_dr->points = 3;
    board->array[7][1]->status = true;
    board->array[7][1]->piece = horse_dr;
    board->array[7][1]->piece->colour = "wh";
    
}
void populate_bishop(board_t *board)
{
    pieces_t* bishop_tl = calloc(1, sizeof(pieces_t));
    bishop_tl->name_of_piece = calloc(1, sizeof(char*));
    bishop_tl->name_of_piece = "B";
    bishop_tl->points = 3;
    board->array[0][2]->piece = bishop_tl;
    board->array[0][2]->status = true;
    board->array[0][2]->piece->colour = ("bl");

    pieces_t* bishop_tr = calloc(1, sizeof(pieces_t));
    bishop_tr->name_of_piece = calloc(1, sizeof(char*));
    bishop_tr->name_of_piece = "B";
    bishop_tr->points = 3;
    board->array[0][5]->piece = bishop_tr;
    board->array[0][5]->status = true;
    board->array[0][5]->piece->colour = ("bl");

    pieces_t* bishop_dl = calloc(1, sizeof(pieces_t));
    bishop_dl->name_of_piece = calloc(1, sizeof(char*));
    bishop_dl->name_of_piece = "B";
    bishop_dl->points = 3;
    board->array[7][5]->piece = bishop_dl;
    board->array[7][5]->status = true;
    board->array[7][5]->piece->colour = ("wh");

    pieces_t* bishop_dr = calloc(1, sizeof(pieces_t));
    bishop_dr->name_of_piece = calloc(1, sizeof(char*));
    bishop_dr->name_of_piece = "B";
    bishop_dr->points = 3;
    board->array[7][2]->piece = bishop_dr;
    board->array[7][2]->status = true;
    board->array[7][2]->piece->colour = ("wh");
}

void populate_kings_and_queens(board_t *board)
{
    pieces_t* Queen_bl = calloc(1, sizeof(pieces_t));
    Queen_bl->name_of_piece = calloc(1, sizeof(char*));
    Queen_bl->name_of_piece = "Q";
    Queen_bl->points = 9;
    board->array[0][3]->piece = Queen_bl; 
    board->array[0][3]->status = true; 
    board->array[0][3]->piece->colour = ("bl");

    pieces_t* Queen_wh = calloc(1, sizeof(pieces_t));
    Queen_wh->name_of_piece = calloc(1, sizeof(char*));
    Queen_wh->name_of_piece = "Q";
    Queen_wh->points = 9;
    board->array[7][3]->piece = Queen_wh; 
    board->array[7][3]->status = true;
    board->array[7][3]->piece->colour = ("wh"); 
    
    pieces_t* King_bl = calloc(1, sizeof(pieces_t));
    King_bl->name_of_piece = calloc(1, sizeof(char*));
    King_bl->name_of_piece = "K";
    King_bl->points = 0;
    board->array[0][4]->piece = King_bl; 
    board->array[0][4]->status = true; 
    board->array[0][4]->piece->colour = ("bl"); 

    pieces_t* King_wh = calloc(1, sizeof(pieces_t));
    King_wh->name_of_piece = calloc(1, sizeof(char*));
    King_wh->name_of_piece = "K";
    King_wh->points = 0;
    board->array[7][4]->piece = King_wh;
    board->array[7][4]->status = true;
    board->array[7][4]->piece->colour = ("wh"); 

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

int main(void)
{
    board_t *board = create_board();
    print_board(board);
    return 0;
}