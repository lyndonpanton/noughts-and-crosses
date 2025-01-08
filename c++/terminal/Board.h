#include <iostream>

#ifndef BOARD_H

#define BOARD_H

class Board
{
    char* m_board = new char[9];
    size_t m_size = 9;

public:
    Board();
    char* get_board() const;
    char& operator[](size_t);
    void print_board() const;
};

#endif
