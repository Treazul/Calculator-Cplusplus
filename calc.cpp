#include "calc.h"
#include "io.h"
#include <iostream>
#include <cmath>

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
            if (y == 0 && x != 0)
            {
                std::cout << "Can't divide by Zero. \n";
                result = x;
                break;
            }
            else if (y == 0 && x == 0)
            {
                result = x;
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
        case 'p':
            result = pow(x, y);
            break;
        default:
            std::cout << "An error has occurred. This mathematical operation can't be done here. However, you shouldn't see this because it should be handled before you reach this point.";
            quitNow(44);
            break;
    }

    return result;
}
