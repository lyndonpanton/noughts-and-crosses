#include "Board.h"

Board::Board()
{
    
}

char* Board::get_board() const
{
    return m_board;
}

void Board::print_board() const
{
    for (int i = 0; i < m_size; i++)
    {
        if (i % 3 == 0)
        {
            for (int i = 0; i < 10; i++) std::cout << "-";
            std::cout << std::endl << "|";
        }
        
        if (m_board[i] == 'X')
        {
            std::cout << " X " << "|";
        }
        else if (m_board[i] == 'O')
        {
            std::cout << " O " << "|";
        }
        else
        {
            std::cout << "  " << "|";
        }

        // Match: 2, 5, 8
        if (i % 3 == 2)
        {
            std::cout << std::endl;
        }

        if (i == m_size - 1)
        {
            for (int i = 0; i < 10; i++) std::cout << "-";
            std::cout << std::endl;
        }
    }
}

char& Board::operator[](size_t index)
{
    return m_board[index];
}
