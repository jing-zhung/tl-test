#include "binary_tree_calculator.hpp"

int main()
{
    std::string operation;
    BinaryTreeCalculator calc;
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
    return 0;
}