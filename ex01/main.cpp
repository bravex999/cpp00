#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    Phonebook   phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
            break;
		}
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
    }
    return 0;
}
