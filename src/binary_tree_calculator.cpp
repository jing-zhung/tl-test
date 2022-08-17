#include "binary_tree_calculator.hpp"

Node::Node(std::string data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() 
{
    // deleting the left and right pointers
    delete left;
    delete right;
}

BinaryTreeCalculator::BinaryTreeCalculator()
{
    std::cout << "Binary Tree Calculator initialized." << std::endl;
    root_ = nullptr;
}

void BinaryTreeCalculator::setInput(std::string operation)
{
    stringToTree(operation);
    //calcAnswer();
}

Node* BinaryTreeCalculator::insertNode(Node* root, std::string operation)
{
    // Split string
    bool not_number = false;
    std::string substr1, substr2, node_data;
    int bracket_counter = 0;

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
            node_data = c;
            substr1 = operation.substr(0, index);
            substr2 = operation.substr(index + 1, std::string::npos);
            not_number = true;
            break;
        }
    }

    if(!not_number)
    {
        node_data = operation;
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
    return root;
}

void BinaryTreeCalculator::stringToTree(std::string operation)
{
    // Remove whitespace
    operation.erase(std::remove_if(operation.begin(), operation.end(), isspace), operation.end());

    std::cout << "Populate tree..." << std::endl;
    root_ = insertNode(root_, operation);
    //std::cout << root_->data << "|" << root_->left->data << "|" << root_->right->data << std::endl;
}

void BinaryTreeCalculator::printTree(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        // Formatting
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "\\--" );

        // print the value of the node
        std::cout << " " << node->data << std::endl;

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

void BinaryTreeCalculator::reset()
{
    std::cout << "Delete tree..." << std::endl;
    delete root_;
}