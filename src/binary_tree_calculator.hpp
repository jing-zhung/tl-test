#include <iostream>
#include <algorithm>

class Node 
{
    public:
        std::string data;
        Node* left;
        Node* right;
        // constructor
        Node(std::string data);
        // destructor
        ~Node();
};

class BinaryTreeCalculator
{
    private:
        Node* root_;
        double answer_;

        void stringToTree(std::string operation);
        Node* insertNode(Node* root, std::string operation);
        void printTree(const std::string& prefix, const Node* node, bool isLeft);
        void calcAnswer();
    public:
        BinaryTreeCalculator();
        void setInput(std::string operation);
        void displayTree();
        double getAnswer();
        void reset();
};