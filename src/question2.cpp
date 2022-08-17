#include "binary_tree_calculator.hpp"

int main()
{
    std::string operation;
    BinaryTreeCalculator calc;
    std::cout << "Type math operation: ";
    std::getline(std::cin, operation);
    calc.setInput(operation);
    calc.reset();
    return 0;
}