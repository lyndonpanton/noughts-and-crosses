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
    ~Board();
    char* get_board() const;
    int get_size() const;
    void initialise_board();
    bool is_full() const;
    char& operator[](size_t);
    void print_board(bool) const;
    bool set_board(int, Symbol);
    bool winner_found();
};

#endif
