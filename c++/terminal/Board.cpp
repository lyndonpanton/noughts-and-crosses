#include "Board.h"

Board::Board()
{
    
}

char* Board::get_board() const
{
    return m_board;
}

void Board::initialise_board()
{
    for (int i = 0; i < m_size; i++)
    {
        m_board[i] = ' ';
    }
}

char& Board::operator[](size_t index)
{
    return m_board[index];
}

void Board::print_board(bool guide) const
{
    for (int i = 0; i < m_size; i++)
    {
        if (i % 3 == 0)
        {
            for (int i = 0; i < 13; i++) std::cout << "-";
            std::cout << std::endl << "|";
        }

        if (guide)
        {
            std::cout << " " << (i + 1) << " " << "|";
        }
        else
        {
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
                std::cout << "   " << "|";
            }
        }

        // Match: 2, 5, 8
        if (i % 3 == 2)
        {
            std::cout << std::endl;
        }

        if (i == m_size - 1)
        {
            for (int i = 0; i < 13; i++) std::cout << "-";
            std::cout << std::endl;
        }
    }
}

bool Board::set_board(int position, Symbol symbol)
{
    if (get_board()[position - 1] == ' ')
    {
        if (symbol == X) m_board[position - 1] = 'X';
        else m_board[position - 1] = 'O';
        
        return true;
    }
    
    return false;
}

bool Board::winner_found()
{
    return false;
}
