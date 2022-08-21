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
    for(char& c : operation)
    {
        if(!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
        {
            return false;
        }
    }
    return true;
}

Node* BinaryTreeCalculator::insertNode(Node* root, std::string operation)
{
    // String processing
    bool not_number = false;
    std::string substr1, substr2, node_data;
    int bracket_counter = 0;
    bool front_negative_number = false;

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

    if (root == nullptr)
    {
        root = new Node(node_data);
    }
    
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
    if(root->left != nullptr && root->right != nullptr)
    {
        string = calcAnswer(root->left) + root->data + calcAnswer(root->right);
    }
    else if(root->right != nullptr)
    {
        string = "0" + root->data + calcAnswer(root->right);
    }
    else if(root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }

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

        // print the value of the node
        std::cout << "(" << node->data  << ")" << std::endl;

        // enter the next tree level - left and right branch
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