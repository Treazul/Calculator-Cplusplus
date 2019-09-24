#include "input.h"
#include "io.h"
#include <iostream>
#include <string>
#include <algorithm>


// Is the input a number?
inline bool is_number(const std::string & s)
{
    // if the string is empty, the first character is not a digit and not a negative or positive, it's not a number
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
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
        std::cout << "Enter a number: ";
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
