#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
// TODO: Create a GUI for this calculator

// Is the input a number?
bool is_number(const std::string &s)
{
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

// Ignore anything that isn't the expected input and clear it all.
void cinIgnore()
{
    std::cin.ignore(32767, '\n');
}

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


double getUserInput()
{
    // Loops until there's a correct input
    while (true)
    {
        std::cout << "Enter a number: ";
        std::string input;
        std::cin >> input;
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
        if (input == '+' || input == '-' || input == '*' || input == '/' || input == '%')
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
            std::cout << "(Valid inputs are +, -, *, / or %) \n";
        }
    }
}


double calculateResult(double x, double y, char z)
{
    double result{ 0 };
    switch (z)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if (y == 0)
            {
                std::cout << "ERROR: TRIED TO DIVIDE BY ZERO. \n";
                quitNow(55);
                break;
            }
            else
            {
                result = x / y;
                break;
            }

        case '%':
            result = fmod(x, y);
            break;
        default:
            std::cout << "An error has occurred. This mathematical operation can't be done here. However, you shouldn't see this because it should be handled before you reach this point.";
            exit(0);
            break;
    }

    return result;
}

// Not strictly required, but why not.
void printResult(double x, char y, double z, double r)
{
    std::cout << "\nThe Result of " << x << " " << y << " " << z << " is " << r << '\n' << '\n';
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
