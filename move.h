/**
 * move.h
 * 
 * the MicroChess project: https://github.com/ripred/MicroChess
 * 
 * header file for MicroChess
 * 
 */
#ifndef MOVE_INCL
#define MOVE_INCL

////////////////////////////////////////////////////////////////////////////////////////
// an entry in a move list
struct move_t 
{
public:
    int8_t    from : NUM_BITS_SPOT,     // the index into the board the move starts at
                to : NUM_BITS_SPOT;     // the index into the board the move finishes at

    int32_t  value;                     // the value of the move

public:
    move_t() /* : from(0), to(0), value(0) */ {}
    move_t(index_t f, index_t t, long v) : from(f), to(t), value(v) {}

};  // move_t

#endif // MOVE_INCL