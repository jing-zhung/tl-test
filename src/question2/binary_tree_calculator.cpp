#include "binary_tree_calculator.hpp"

BinaryTreeCalculator::BinaryTreeCalculator()
{
    std::cout << "Binary Tree Calculator initialized." << std::endl;
    root_ = nullptr;
    is_valid_ = true;
}

void BinaryTreeCalculator::setInput(std::string operation)
{
    // Remove whitespace
    operation.erase(std::remove_if(operation.begin(), operation.end(), isspace), operation.end());

    if(checkValidity(operation))
    {
        stringToTree(operation);
        answer_ = calcAnswer(root_);
    }
    else
    {
        is_valid_ = false;
    }
}

bool BinaryTreeCalculator::checkValidity(std::string operation)
{
    int bracket_counter = 0;

    for(char& c : operation)
    {
        // Check if string only contains numbers and math operators
        if(!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
        {
            return false;
        }
        else if(c == '(')
        {
            bracket_counter++;
        }
        else if(c == ')')
        {
            bracket_counter--;
        }
    }

    // Check if brackets usage is valid
    if(bracket_counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node* BinaryTreeCalculator::insertNode(Node* root, std::string operation)
{
    bool not_number = false;
    std::string substr1, substr2, node_data;
    int bracket_counter = 0;
    bool front_negative_number = false;

    // Deconstruct string into 2 math operations separated by a math operator
    for(char& c : operation) 
    {
        if(c == '(')
        {
            bracket_counter++;
        }
        else if(c == ')')
        {
            bracket_counter--;
        }

        if(!bracket_counter && (c == '+' || c == '-' || c == '*' || c == '/'))
        {
            int index = &c - &operation[0];
            if(c == '-' && index == 0)
            {
                front_negative_number = true;
                continue;
            }
            node_data = c;
            substr1 = operation.substr(0, index);
            substr2 = operation.substr(index + 1, std::string::npos);
            not_number = true;
            break;
        }
    }

    // Set data of node
    if(!not_number)
    {
        if(front_negative_number)
        {
            node_data = '-';
            substr1 = "";
            substr2 = operation.substr(1, std::string::npos);
        }
        else
        {
            node_data = operation;
        }
    }

    // Clear redundant brackets
    if(substr1.front() == '(' && substr1.back() == ')')
    {
        substr1 = substr1.substr(1, substr1.size() - 2);
    }
    if(substr2.front() == '(' && substr2.back() == ')')
    {
        substr2 = substr2.substr(1, substr2.size() - 2);
    }

    // Create new node
    if (root == nullptr)
    {
        root = new Node(node_data);
    }
    
    // Insert left and right nodes
    if(not_number)
    {
        root->left = insertNode(root->left, substr1);
        root->right = insertNode(root->right, substr2);
    }
    else if(front_negative_number)
    {
        root->right = insertNode(root->right, substr2);
    }
    return root;
}

void BinaryTreeCalculator::stringToTree(std::string operation)
{
    std::cout << "Populate tree..." << std::endl;
    root_ = insertNode(root_, operation);
}

void BinaryTreeCalculator::getResult(double &result, char op, double number)
{
    switch(op)
    {
        case '+':
            result += number;
            break;
        case '-':
            result -= number;
            break;
        case '*':
            result *= number;
            break;
        case '/':
            // Check for undefined answer
            if(number == 0)
            {
                is_valid_ = false;
                result = 0;
            }
            else
            {
                result /= number;
            }
            break;
        default:
            is_valid_ = false;
    }
}

std::string BinaryTreeCalculator::calcAnswer(Node* root)
{
    std::string string;
    double answer, number;
    char op;
    // If it has left and right nodes, it's a math operator
    if(root->left != nullptr && root->right != nullptr)
    {
        string = calcAnswer(root->left) + root->data + calcAnswer(root->right);
    }
    // If it has only right node, it's a negative number of right node
    else if(root->right != nullptr)
    {
        string = "0" + root->data + calcAnswer(root->right);
    }
    // If no left or right nodes, it's a leaf node containing a number
    else if(root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

    // Get answer
    std::stringstream math(string);
    math >> answer;
    math >> op >> number;
    getResult(answer, op, number);
    return std::to_string(answer);
}

void BinaryTreeCalculator::printTree(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        // Formatting
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "\\--" );

        // Print the value of the node
        std::cout << "(" << node->data  << ")" << std::endl;

        // Enter the next tree level - left and right branch
        printTree( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printTree( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void BinaryTreeCalculator::displayTree()
{    
    std::cout << "Display tree:" << std::endl;
    printTree("", root_, false);
}

double BinaryTreeCalculator::getAnswer()
{
    // Convert answer from string to double
    return std::stod(answer_);
}

bool BinaryTreeCalculator::isValid()
{
    return is_valid_;
}

void BinaryTreeCalculator::reset()
{
    std::cout << "Delete tree..." << std::endl;
    delete root_;
    root_ = nullptr;
    is_valid_ = true;
}