#include <iostream>
#include <cmath>
#include <algorithm>

void quitNow(int code);

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

        case 'p':
            result = pow(x, y);
            break;
        default:
            std::cout << "An error has occurred. This mathematical operation can't be done here. However, you shouldn't see this because it should be handled before you reach this point.";
            exit(0);
            break;
    }

    return result;
}
