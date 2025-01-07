#include <iostream>
#include <vector>

void check_record();
void choose_game_mode();
void clear_record();
void play_game();
void print_introduction();
void print_options(std::vector<std::string>&);
void set_options(std::vector<std::string>&);
void exit_game(bool&);

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
            
            std::cout << "Enter your option (1 - 4): ";
            std::cin >> option;

            std::cout << std::endl;

            switch (option)
            {
                case 1:
                    play_game();
                    break;
                case 2:
                    check_record();
                    break;
                case 3:
                    clear_record();
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

void check_record()
{
    // Print Player vs. Computer record

    // Print player vs. player record (separate records by xs and os)
}

void clear_record()
{

}

void choose_game_mode()
{

}

void exit_game(bool& playing)
{
    playing = false;

    std::cout << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
}

void play_game()
{

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

    // Play
    // Check record
    // Exit

    std::cout << std::endl;
}

void set_options(std::vector<std::string>& options)
{
    options.push_back("Play");
    options.push_back("Check record");
    options.push_back("Clear record");
    options.push_back("Exit");
}