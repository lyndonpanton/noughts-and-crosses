#include <iostream>
#include "Symbol.h"

#ifndef BOARD_H

#define BOARD_H

class Board
{
    char* m_board = new char[9];
    size_t m_size = 9;

public:
    Board();
    char* get_board() const;
    void initialise_board();
    char& operator[](size_t);
    void print_board(bool) const;
    bool set_board(int, Symbol);
    bool winner_found();
};

#endif
