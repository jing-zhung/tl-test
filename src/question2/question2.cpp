#include "binary_tree_calculator.hpp"

int main()
{
    // Initialize calculator
    std::string operation;
    BinaryTreeCalculator calc;
    std::cout << "Math operation must only contain numbers or the following symbols: ( ) + - * /" << std::endl;

    // Execution loop
    std::string keyboard_input;
    while(true)
    {
        std::cout << "Type math operation: ";
        std::getline(std::cin, operation);
        calc.setInput(operation);
        if(calc.isValid())
        {
            calc.displayTree();
            std::cout << "Answer: " << calc.getAnswer() << std::endl;
        }
        else
        {
            std::cout << "Math operation invalid" << std::endl;
        }
        calc.reset();
        std::cout << std::endl << "####################" << std::endl;
    }
    return 0;
}