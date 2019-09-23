#include "io.h"
#include <iostream>
#include <string>

// Quit with a code, specific codes will give me an idea of where something went wrong.

void quitNow(int code)
{
    if (code == 0)
    {
        std::cout << "Thanks for trying my calculator! \n";
        exit(code);
    }
    else
    {
        std::cout << "An error has occurred with exit code " << code << '\n';
        exit(code);
    }

}

// Print the result of the mathmatical equations.
void printResult(double x, char y, double z, double r)
{
    std::string f;
    switch (y)
    {
        case '*':
            f = "times";
            break;
        case '/':
            f = "divided by";
            break;
        case '+':
            f = "plus";
            break;
        case '-':
            f = "minus";
            break;
        case '%':
            f = "modulo";
            break;
        case 'p':
            f = "to the power of";
            break;
        default:
            f = "INVALID SELECTION";
            break;

    }
    std::cout << "\nThe Result of " << x << " " << f << " " << z << " is " << r << '\n';
    std::cout << "------------------------------------------------------------ \n \n";
}

//End of Result Line.
