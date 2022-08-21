#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

class Node 
{
    public:
        std::string data;
        Node* left;
        Node* right;
        // constructor
        Node(std::string data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        };
        // destructor
        ~Node()
        {
            // delete the left and right pointers
            if(left != nullptr)
            {
                delete left;
                left = nullptr;
            }
            if(right != nullptr)
            {
                delete right;
                right = nullptr;
            }
        };
};

class BinaryTreeCalculator
{
    private:
        Node* root_;
        std::string answer_;
        bool is_valid_;

        bool checkValidity(std::string operation);
        void stringToTree(std::string operation);
        Node* insertNode(Node* root, std::string operation);
        void printTree(const std::string& prefix, const Node* node, bool isLeft);
        void getResult(double &result, char op, double number);
        std::string calcAnswer(Node* root);
    public:
        BinaryTreeCalculator();
        void setInput(std::string operation);
        void displayTree();
        double getAnswer();
        bool isValid();
        void reset();
};