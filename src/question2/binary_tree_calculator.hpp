#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

// Define node
class Node 
{
    public:
        std::string data;
        Node* left;
        Node* right;
        // Constructor
        Node(std::string data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        };
        // Destructor
        ~Node()
        {
            // Delete the left and right pointers
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


// Define binary tree calculator
class BinaryTreeCalculator
{
    private:
        Node* root_;
        std::string answer_;
        bool is_valid_;

        /**
         * @brief Check if math operation is valid
         * @param operation Math operation in string format
         * @return boolean if answer is valid or not
         */
        bool checkValidity(std::string operation);

        /**
         * @brief Convert math operation string to binary tree
         * @param operation Math operation in string format
         */
        void stringToTree(std::string operation);

        /**
         * @brief Recursive function to insert nodes into binary tree
         * @param root Pointer to root node
         * @param operation Math operation in string format
         * @return pointer to inserted node
         */
        Node* insertNode(Node* root, std::string operation);

        /**
         * @brief Recursive function to traverse binary tree to print binary tree in terminal
         * @param prefix String to format print out
         * @param node Pointer to node
         * @param isLeft Boolean if node is left node or not
         */
        void printTree(const std::string& prefix, const Node* node, bool isLeft);

        /**
         * @brief Calculate math operation answer
         * @param result Answer
         * @param op Math operator
         * @param number Number used in math operation
         */
        void getResult(double &result, char op, double number);

        /**
         * @brief Recursive function to traverse binary tree to get final answer
         * @param root Pointer to root node
         * @return alculated answer in string format
         */
        std::string calcAnswer(Node* root);

    public:
        BinaryTreeCalculator();

        /**
         * @brief Set math operation input string
         * @param operation Math operation in string format
         */
        void setInput(std::string operation);

        /**
         * @brief Print binary to terminal
         */
        void displayTree();

        /**
         * @brief Get the answer of math operation
         * @return answer of math operation
         */
        double getAnswer();

        /**
         * @brief Check if answer is valid
         * @return boolean if answer is valid or not
         */
        bool isValid();

        /**
         * @brief Reset the calculator by deleting the binary tree
         */
        void reset();
};