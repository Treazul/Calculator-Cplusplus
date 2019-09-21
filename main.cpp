#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "input.h"
#include "calc.h"

// TODO: More mathmatical equations such as squaring, rooting and so forth.
// TODO: Create a GUI for this calculator

//
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





// Not strictly required, but why not.
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
    std::cout << "\nThe Result of " << x << " " << f << " " << z << " is " << r << '\n' << '\n';
}

int main()
{
    while(true)
    {
        // Get first number from user
        double firstInput = getUserInput();

        // Get mathematical operation from user
        char mathOperation = getMathematicalOperation();

        // Get second number from user
        double secondInput = getUserInput();

        // Calculate result
        double result = calculateResult(firstInput, secondInput, mathOperation);

        // Print result
        printResult(firstInput, mathOperation, secondInput, result);
    }
    return 0;

}
