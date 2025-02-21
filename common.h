#pragma once
#include <stdbool.h>
#define EIGHT 8
typedef struct pieces pieces_t;
typedef struct board board_t;
typedef struct positions positions_t;
typedef struct id_of_board id_of_board_t;
typedef struct move move_t;


struct positions {
    pieces_t* piece;
    bool status;
    id_of_board_t* id;
};
struct id_of_board {
    char first;
    int second;
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

struct move {
    id_of_board_t *from;
    id_of_board_t *to;
};