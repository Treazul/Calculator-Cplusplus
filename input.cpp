#include "input.h"
#include "io.h"
#include <iostream>
#include <string>
#include <algorithm>


// Is the input a number?
bool is_number(const std::string &s)
{
    // To be honest, I don't know what this does. Someone suggested this as a way of checking if it's a number and it works!
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

// Ignore anything that isn't the expected input and clear it all.
void cinIgnore()
{
    std::cin.ignore(32767, '\n');
}


double getUserInput()
{
    // Loops until there's a correct input
    while (true)
    {
        std::cout << "Enter a positive number: ";
        std::string input;
        std::cin >> input;
        // If it's a number, ignore the extranious stuff and turn the result into a double from a string.
        if(is_number(input))
        {
            cinIgnore();
            double result = std::stod(input);
            return result;
        }
        else if (input == "q")
        {
            quitNow(0);
        }
        else
        {
            std::cout << "That's not a valid number. Please input a number or q to quit \n";
        }
    }
}

char getMathematicalOperation()
{
    while (true) // Loops until get's a correct input
    {
        std::cout << "Enter the mathematical operation to use: ";
        char input{ };
        std::cin >> input;
        cinIgnore();
        if (input == '+' || input == '-' || input == '*' || input == '/' || input == '%' || input == 'p')
        {
            return input;
        }
        else if (input == 'q')
        {
            quitNow(0);
        }
        else
        {
            std::cout << "That's not a mathematical operation that I can do. Sorry! \n";
            std::cout << "(Valid inputs are +, -, *, /, % or (p)ower ) \n";
        }
    }
}
