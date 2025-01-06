#include <iostream>
#include <vector>

void check_record();
void choose_game_mode();
void play_game(bool);
void print_introduction();
void print_options(std::vector<std::string>&);
void set_options(std::vector<std::string>&);

int main()
{
    print_introduction();

    std::vector<std::string> options;
    
    set_options(options);

    bool playing = false;

    while (playing)
    {
        print_options(options);

        break;
    }

    return 0;
}

void check_record()
{
    // Print Player vs. Computer record

    // Print player vs. player record (separate records by xs and os)
}

void play_game(bool isXFirst)
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