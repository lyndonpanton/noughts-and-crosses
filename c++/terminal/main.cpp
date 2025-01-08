#include <iostream>
#include <vector>
#include "GameMode.h"
#include "Symbol.h"
#include "Board.h"

/*
    Input format:

    { int } { int }

    0 <= int <= 2

    i.e., 1 2 => second row (index 1), third column (index 2)
*/

/*
    Todo

    - Player can check records of the games
    - Player can clear records of the games
    - Player can choose to play against another player or the computer
    - Player can choose to play as Xs or Os
    - 

    - Change all "set" functions to return void
    - Change all "get" functions to return a type
*/

void delete_record();
void exit_game(bool&);
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
                    read_record();
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

void play_game_vs_computer()
{

}

void play_game_vs_player()
{

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

void read_record()
{
    // Print Player vs. Computer record

    // Print player vs. player record (separate records by xs and os)
    std::cout << "Record checked..." << std::endl;
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
                starting_symbol = X;
                valid_symbol_chosen = true;
                break;
            case 2:
                starting_symbol = O;
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
                player_symbol = X;
                valid_symbol_chosen = true;
                break;
            case 2:
                player_symbol = O;
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
    board.print_board();

    // Start game loop...
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
    board.print_board();

    // Start game loop...
}
