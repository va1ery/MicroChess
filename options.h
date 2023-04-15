/**
 * options.h
 * 
 * the MicroChess project: https://github.com/ripred/MicroChess
 * 
 * The options_t structure holds flags that are used during the game
 * to enable or disable various features of the chess engine.
 * 
 */
#ifndef OPTIONS_INCL
#define OPTIONS_INCL

////////////////////////////////////////////////////////////////////////////////////////
// the settings for a game
struct options_t {
public:
    uint8_t     random : 1,     // add randomness to the game?
             profiling : 1;     // are we profiling the engine?
    uint8_t     maxply;         // the maximum ply level
    uint32_t    move_limit;     // the maximum number of moves allowed in a full game
    uint32_t    seed;           // the starting seed hash for prn's
    print_t     print_level;    // the verbosity setting for the level of output
    Bool        continuous;     // True if we play gamesone after another

    // adjustable multipiers to alter importance of mobility or center proximity
    // during board evaluation. season to taste
    static long constexpr mobilityBonus = 3L;
    static long constexpr   centerBonus = 10L;
public:

    options_t() : 
        random(False), 
        profiling(False), 
        maxply(MAX_PLY),
        move_limit(MOVE_LIMIT),
        seed(PRN_SEED),
        print_level(Debug1),
        continuous(False)
    {}

};  // options_t

#endif  // OPTIONS_INCL