/**
 * rook.cpp
 * 
 * the MicroChess project: https://github.com/ripred/MicroChess
 * 
 * move generation for rooks
 * 
 */

#include <Arduino.h>
#include "MicroChess.h"

/*
 * evaluate the moves for a rook against the best move so far
 *
 */
// void add_rook_moves(piece_gen_t &gen) {
//     move_t &move = gen.move;
//     move_t &best = gen.best;
//     generator_t *callback = gen.callme;

//     bool continue_dir[4] = { true, true, true, true };
//     Piece   const p = board.get(move.from);
//     Color   const side = getSide(p);

//     index_t const col = move.from % 8;
//     index_t const row = move.from / 8;

//     for (unsigned i=0; i < NUM_ROOK_OFFSETS; i++) {
//         offset_t const * const ptr = pgm_get_far_address(game.rook_offsets);
//         index_t  const xoff = pgm_read_byte(&ptr[i].x);
//         index_t  const yoff = pgm_read_byte(&ptr[i].y);
//         index_t  const to_col = col + xoff;
//         index_t  const to_row = row + yoff;
//         if (isValidPos(to_col, to_row)) {
//             index_t to = to_col + to_row * 8;
//             Piece const op = board.get(to);

//             if (xoff == 0) {
//                 int const index = yoff > 0 ? 0 : 1; // N or S
//                 if (continue_dir[index]) {
//                     if (isEmpty(op)) {
//                         move.to = to;
//                         callback(move, best);
//                     } else {
//                         continue_dir[index] = false;
//                         if (side != getSide(op)) {
//                             move.to = to;
//                             callback(move, best);
//                         }
//                     }
//                 }
//             } else if (yoff == 0) {
//                 int const index = xoff > 0 ? 2 : 3; // E or W
//                 if (continue_dir[index]) {
//                     if (isEmpty(op)) {
//                         move.to = to;
//                         callback(move, best);
//                     } else {
//                         continue_dir[index] = false;
//                         if (side != getSide(op)) {
//                             move.to = to;
//                             callback(move, best);
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

// void add_rook_moves(piece_gen_t &gen) {
//     move_t &move = gen.move;
//     move_t &best = gen.best;
//     generator_t *callback = gen.callme;

//     index_t const dirs[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
//     Bool continue_dir[4] = { True, True, True, True };
//     Piece   const p = board.get(move.from);
//     Color   const side = getSide(p);

//     index_t const col = move.from % 8;
//     index_t const row = move.from / 8;

//     for (auto const &dir : dirs) {
//         index_t x = col + dir[0];
//         index_t y = row + dir[1];

//         index_t offset = 0;
//         while (isValidPos(x, y) && continue_dir[offset]) {
//             index_t const to = x + y * 8;
//             Piece   const op = board.get(to);

//             if (isEmpty(op)) {
//                 move.to = to;
//                 callback(move, best);
//             }
//             else if (side != getSide(op)) {
//                 continue_dir[offset] = False;
//                 move.to = to;
//                 callback(move, best);
//                 break;
//             }
//             else {
//                 continue_dir[offset] = False;
//                 break;
//             }

//             x += dir[0];
//             y += dir[1];
//             offset++;
//         }
//     }
// }

void add_rook_moves(piece_gen_t &gen) {
    move_t &move = gen.move;
    move_t &best = gen.best;
    generator_t *callback = gen.callme;

    int const dirs[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    Piece const p = board.get(move.from);
    Color const side = getSide(p);

    index_t const col = move.from % 8;
    index_t const row = move.from / 8;

    for (auto const &dir : dirs) {
        index_t x = col + dir[0];
        index_t y = row + dir[1];

        while (isValidPos(x, y)) {
            move.to = x + y * 8;
            Piece const op = board.get(move.to);

            if (isEmpty(op)) {
                callback(move, best);
            }
            else if (side != getSide(op)) {
                callback(move, best);
                break;
            }
            else if (side == getSide(op)) {
                break;
            }

            x += dir[0];
            y += dir[1];
        }
    }
}
