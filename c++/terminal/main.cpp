#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

#include "GameMode.h"
// "Symbol.h" is in "Board.h"
#include "Board.h"

/*
    Input format:

    { int } { int }

    0 <= int <= 2

    i.e., 1 2 => second row (index 1), third column (index 2)
*/

/*
    Record format:
    
    { Player 1 wins vs. Player }
    { Player 2 wins vs. Player }
    { Empty line }
    { Player wins vs. Computer }
    { Computer wins vs. Computer }

*/

/*
    Todo

    - Player can check records of the games
    - Player can clear records of the games
    - Player can update records of the games
    - Record is updated when player finishes game (vs. computer)
    - Record is updated when player finishes game (vs. player)
    - Add destructor to RAII Board class

    - Change all "set" functions to return void
    - Change all "get" functions to return a type
*/

void computer_place_symbol(Board&, Symbol&);
void delete_record();
void exit_game(bool&);
void get_record();
void player_place_symbol(Board&, Symbol&);
void play_game_vs_computer();
void play_game_vs_player();
void print_game_modes();
void print_introduction();
void print_options(std::vector<std::string>&);
void print_symbols(std::vector<char>&);
void read_record();
GameMode set_game_mode();
void set_game_modes(std::vector<std::string>&);
void set_options(std::vector<std::string>&);
void set_starting_symbol(Symbol&);
void set_symbol(Symbol&);
void set_symbols(std::vector<char>&);
void start_game();
void start_game_vs_computer();
void start_game_vs_player();
void update_record(GameMode&, bool);

int main()
{
    print_introduction();

    std::vector<std::string> options;
    
    set_options(options);

    bool playing = true;

    while (playing)
    {
        bool valid_option = true;

        do
        {
            int option;
            print_options(options);
            
            std::cout << "What would you like to do (1 - 4)? ";
            std::cin >> option;

            std::cout << std::endl;

            switch (option)
            {
                case 1:
                    start_game();
                    break;
                case 2:
                    get_record();
                    break;
                case 3:
                    delete_record();
                    break;
                case 4:
                    exit_game(playing);
                    break;
                default:
                    valid_option = false;
                    std::cout << "Invalid option chosen..." << std::endl;
            }

            std::cout << std::endl;
        } while (!valid_option);
    }

    return 0;
}

void computer_place_symbol(Board& board, Symbol& symbol)
{
    int size = 0;

    for (int i = 0; i < board.get_size(); i++)
    {
        if (board.get_board()[i] == ' ')
        {
            size++;
        }
    }

    int* valid_tile_indexes = new int[size];
    int index = 0;

    for (int i = 0; i < board.get_size(); i++)
    {
        if (board.get_board()[i] == ' ')
        {
            // Board is 1-index based
            valid_tile_indexes[index] = i + 1;
            index++;
        }
    }

    srand(time(0));
    
    int position = valid_tile_indexes[rand() % size];
    std::cout << "Computer placed symbol at position " << position << std::endl;
    board.set_board(position, symbol);

    std::cout << std::endl;
}

void delete_record()
{
    std::cout << "Record cleared..." << std::endl;
}

void exit_game(bool& playing)
{
    playing = false;

    std::cout << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
}

void get_record()
{
    // std::cout << std::endl;

    // std::ifstream record("record.txt");
    std::ifstream record("record.txt");

    if (record.good())
    {
        int player_one_win_count;
        int player_two_win_count;
        int player_vs_computer_win_count;
        int computer_vs_player_win_count;

        while (record >> player_one_win_count)
        {
            record >> player_two_win_count >> player_vs_computer_win_count
                >> computer_vs_player_win_count;

            std::cout << "Player one has won " << player_one_win_count;
            std::cout << " time(s)!" << std::endl;

            std::cout << "Player two has won " << player_two_win_count;
            std::cout << " time(s)!" << std::endl;

            
            std::cout << "Player has won (vs. Computer) ";
            std::cout << player_vs_computer_win_count << " time(s)!" << std::endl;

            std::cout << "Player has won " << computer_vs_player_win_count;
            std::cout << " time(s)!" << std::endl;
        }

        std::cout << std::endl << "Record updated" << std::endl;
    }
    else
    {
        std::cout << "Record file not found..." << std::endl;
    }

    std::cout << std::endl;

    record.close();
}

void play_game_vs_computer()
{

}

void play_game_vs_player()
{

}

void player_place_symbol(Board& board, Symbol& symbol)
{
    bool valid_position = false;

    while (!valid_position)
    {
        int position;

        std::cout << "Where would you like to place you like to place your ";
        std::cout << "symbol (1 - 9)? ";

        std::cin >> position;

        // 0 < position && position < 10

        if (0 < position && position < 10)
        {
            if (board.set_board(position, symbol))
            {
                valid_position = true;
            }
            else
            {
                std::cout << "Invalid position entered..." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid position entered..." << std::endl;
        }

        std::cout << std::endl;
    }
}

void print_game_modes()
{
    std::cout << std::endl;

    std::vector<std::string> game_modes;
    set_game_modes(game_modes);

    for (int i = 0; i < game_modes.size(); i++)
    {
        std::cout << (i + 1) << ": vs. " << game_modes.at(i) << std::endl;
    }

    std::cout << std::endl;
}

void print_introduction()
{
    std::cout << std::endl;
    std::cout << "Welcome to Noughts and Crosses!" << std::endl;
    std::cout << std::endl;
}

void print_options(std::vector<std::string>& options)
{
    std::cout << "What would you like to do?" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < options.size(); i++)
    {
        std::cout << (i + 1) << ": " << options.at(i) << std::endl;
    }

    std::cout << std::endl;
}

void print_symbols(std::vector<char>& symbols)
{
    for (int i = 0; i < symbols.size(); i++)
    {
        std::cout << (i + 1) << ": " << symbols.at(i) << std::endl;
    }
}

GameMode set_game_mode()
{
    std::cout << "What game mode would you like to play? " << std::endl;

    bool valid_game_mode_chosen = true;
    GameMode game_mode;

    do
    {
        print_game_modes();

        std::cout << "Enter your option (1 - 2): ";

        int game_mode_chosen;
        std::cin >> game_mode_chosen;

        switch (game_mode_chosen)
        {
            case 1:
                game_mode = COMPUTER;
                valid_game_mode_chosen = true;
                break;
            case 2:
                game_mode = PLAYER;
                valid_game_mode_chosen = true;
                break;
            default:
                std::cout << "Invalid game mode chosen..." << std::endl;
                valid_game_mode_chosen = false;
        }

    } while (!valid_game_mode_chosen);

    return game_mode;
}

void set_game_modes(std::vector<std::string>& game_modes)
{
    game_modes.push_back("Computer");
    game_modes.push_back("Player");
}

void set_options(std::vector<std::string>& options)
{
    options.push_back("Play");
    options.push_back("Check record");
    options.push_back("Clear record");
    options.push_back("Exit");
}

void set_starting_symbol(Symbol& starting_symbol)
{
    std::cout << std::endl;

    std::vector<char> symbols;
    set_symbols(symbols);

    bool valid_symbol_chosen = true;

    do
    {
        std::cout << "Which symbol is going first (1 - 2)? " << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < symbols.size(); i++)
        {
            std::cout << (i + 1) << ": " << symbols.at(i) << std::endl;
        }

        std::cout << std::endl;

        int symbol;
        std::cout << "Enter your choice (1 - 2): ";
        std::cin >> symbol;

        switch (symbol)
        {
            case 1:
                starting_symbol = Symbol::X;
                valid_symbol_chosen = true;
                break;
            case 2:
                starting_symbol = Symbol::O;
                valid_symbol_chosen = true;
                break;
            default:
                std::cout << "Invalid option chosen..." << std::endl;
                valid_symbol_chosen = false;
        }

        std::cout << std::endl;
    } while (!valid_symbol_chosen);

}

void set_symbol(Symbol& player_symbol)
{
    std::cout << std::endl;

    std::vector<char> symbols;
    set_symbols(symbols);

    bool valid_symbol_chosen = true;

    do
    {
        std::cout << "What symbol would you like to use (1 - 2)? " << std::endl;
        std::cout << std::endl;

        print_symbols(symbols);

        std::cout << std::endl;

        int symbol;
        std::cout << "Enter your choice (1 - 2): ";
        std::cin >> symbol;

        switch (symbol)
        {
            case 1:
                player_symbol = Symbol::X;
                valid_symbol_chosen = true;
                break;
            case 2:
                player_symbol = Symbol::O;
                valid_symbol_chosen = true;
                break;
            default:
                std::cout << "Invalid option chosen..." << std::endl;
                valid_symbol_chosen = false;
        }

        std::cout << std::endl;
    } while (!valid_symbol_chosen);
}

void set_symbols(std::vector<char>& symbols)
{
    symbols.push_back('X');
    symbols.push_back('O');
}

void start_game()
{
    std::cout << "Starting up game..." << std::endl;
    std::cout << std::endl;

    GameMode game_mode = set_game_mode();

    if (game_mode == COMPUTER)
    {
        start_game_vs_computer();
    }
    else if (game_mode == PLAYER)
    {
        start_game_vs_player();
    }
}

void start_game_vs_computer()
{
    std::cout << std::endl;
    std::cout << "Starting game vs. Computer..." << std::endl;

    // What symbol are you using (X or O)?
    Symbol player_symbol;
    set_symbol(player_symbol);

    if (player_symbol == X)
    {
        std::cout << "Player is using Xs" << std::endl;
    }
    else
    {
        std::cout << "Player is using Os" << std::endl;
    }

    // Who is going first (X or O)?
    Symbol starting_symbol;
    set_starting_symbol(starting_symbol);

    if (player_symbol == X)
    {
        if (starting_symbol == X)
        {
            std::cout << "Player is going first (X)" << std::endl;
        }
        else
        {
            std::cout << "Computer is going first (O)" << std::endl;

        }
    } else
    {
        if (starting_symbol == X)
        {
            std::cout << "Computer is going first (X)" << std::endl;
        }
        else
        {
            std::cout << "Player is going first (O)" << std::endl;
        }
    }

    std::cout << std::endl;

    Board board;
    board.initialise_board();

    Symbol current_player = starting_symbol;
    bool first_turn = true;
    bool winner = false;
    bool full = false;

    // Start game loop...

    /*
        Requirements

        - Player should enter a number 1 to 9
        - Player should be asked to enter a number again if an invalid number is
        entered
        - Computer should retrieve all empty cells
        - Computer should pick a random empty cell to place their symbol in
    */
    while (!winner && !full)
    {
        board.print_board(first_turn);

        if (first_turn) first_turn = !first_turn;

        if (current_player == X)
        {
            std::cout << "X's turn" << std::endl;
        }
        else
        {
            std::cout << "Os turn" << std::endl;
        }

        if (current_player == player_symbol)
        {
            player_place_symbol(board, current_player);
        }
        else
        {
            computer_place_symbol(board, current_player);
        }
        
        std::cout << std::endl;
        std::cout << std::endl;

        winner = board.winner_found();
        full = board.is_full();

        if (!winner) current_player = (current_player == Symbol::X) ? Symbol::O : Symbol::X;
    }

    board.print_board(first_turn);

    if (winner)
    {
        if (current_player == Symbol::X && player_symbol == X
            || current_player == Symbol::O && player_symbol == O
        )
        {
            std::cout << "You win! Good job!" << std::endl;
        }
        else
        {
            std::cout << "Computer wins... Better luck next time..." << std::endl;
        }
    }
    else
    {
        std::cout << "Game is a draw..." << std::endl;
    }

    std::cout << std::endl;
}

void start_game_vs_player()
{
    std::cout << std::endl;
    std::cout << "Starting game vs. Player..." << std::endl;

    // Who is going first (X or O)?
    Symbol starting_symbol;
    set_starting_symbol(starting_symbol);

    if (starting_symbol == X)
    {
        std::cout << "X is going first..." << std::endl;
    } else
    {
        std::cout << "O is going first..." << std::endl;
    }

    std::cout << std::endl;

    Board board;
    board.initialise_board();

    Symbol current_player = starting_symbol;
    bool first_turn = true;
    bool winner = false;
    bool full = false;
    
    while (!winner && !full)
    {
        board.print_board(first_turn);

        if (first_turn) first_turn = !first_turn;

        if (current_player == X)
        {
            std::cout << "X's turn" << std::endl;
        }
        else
        {
            std::cout << "Os turn" << std::endl;
        }
        
        std::cout << std::endl; 

        player_place_symbol(board, current_player);

        std::cout << std::endl;

        winner = board.winner_found();
        full = board.is_full();

        if (!winner) current_player = (current_player == Symbol::X) ? Symbol::O : Symbol::X;
    }

    board.print_board(first_turn);

    if (winner)
    {
        if (current_player == Symbol::X) std::cout << "X ";
        else std::cout << "O ";
        
        std::cout << "wins! Kudos to you!" << std::endl;
    }
    else
    {
        std::cout << "Game is a draw..." << std::endl;
    }

    std::cout << std::endl;
}

void update_record(GameMode& game_mode, bool winner)
{
    // For COMPUTER game mode, winner == false means computer won and winner ==
    // true means player won

    // For PLAYER game mode, winner == false means player 2 won and winner ==
    // true means player 1 won

    if (game_mode == COMPUTER)
    {
        if (winner)
        {

        }
        else
        {

        }
    }
    else
    {
        if (winner)
        {

        }
        else
        {

        }
    }
}
