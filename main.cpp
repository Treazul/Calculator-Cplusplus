#include "input.h"
#include "calc.h"
#include "io.h"
// TODO: More mathmatical equations such as squaring, rooting and so forth.
// TODO: Create a GUI for this calculator

//

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
