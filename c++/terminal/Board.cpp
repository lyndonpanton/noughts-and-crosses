#include "Board.h"

Board::Board()
{
    
}

Board::~Board()
{
    delete [] m_board;
}

char* Board::get_board() const
{
    return m_board;
}

int Board::get_size() const
{
    return m_size;
}

void Board::initialise_board()
{
    for (int i = 0; i < m_size; i++)
    {
        m_board[i] = ' ';
    }
}

bool Board::is_full() const
{
    for (int i = 0; i < m_size; i++)
    {
        if (m_board[i] == ' ') return false;
    }

    return true;
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
    /*
        Win conditions

        1, 2, 3
        4, 5, 6
        7, 8, 9

        1, 4, 7
        2, 5, 8
        3, 6, 9

        1, 5, 9
        3, 5, 7
    */

    if (m_board[0] != ' ' && m_board[0] == m_board[1] && m_board[1] == m_board[2])
    {
        return true;
    }
    else if (m_board[3] != ' ' && m_board[3] == m_board[4] && m_board[4] == m_board[5])
    {
        return true;
    }
    else if (m_board[6] != ' ' && m_board[6] == m_board[7] && m_board[7] == m_board[8])
    {
        return true;
    }
    else if (m_board[0] != ' ' && m_board[0] == m_board[3] && m_board[3] == m_board[6])
    {
        return true;
    }
    else if (m_board[1] != ' ' && m_board[1] == m_board[4] && m_board[4] == m_board[7])
    {
        return true;
    }
    else if (m_board[2] != ' ' && m_board[2] == m_board[5] && m_board[5] == m_board[8])
    {
        return true;
    }
    else if (m_board[0] != ' ' && m_board[0] == m_board[4] && m_board[4] == m_board[8])
    {
        return true;
    }
    else if (m_board[2] != ' ' && m_board[2] == m_board[4] && m_board[4] == m_board[6])
    {
        return true;
    }
    else
    {
        return false;
    }
}
