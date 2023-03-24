/**
 * knight.cpp
 * 
 * move generation for knights
 * 
 */

#include <Arduino.h>
#include "MicroChess.h"

////////////////////////////////////////////////////////////////////////////////////////
// add the moves for a knight to the proper list (game.moves1 or game.moves2)
void add_knight_moves(Piece p, index_t from, index_t col, index_t row, index_t fwd, Color side) {
    for (unsigned i=0; i < NUM_KNIGHT_OFFSETS; i++) {
        offset_t *ptr = pgm_get_far_address(knight_offsets);
        index_t to_col = col + ptr[i].x * fwd;
        index_t to_row = row + ptr[i].y * fwd;
        if (isValidPos(to_col, to_row)) {
            index_t to = to_col + (to_row * 8);
            Piece const op = board.get(to);
            if (Empty == getType(op) || getSide(op) != side) {
                add_move(side, from, to, 0);
            }
        }
    }
}