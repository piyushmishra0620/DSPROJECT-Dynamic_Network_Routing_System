#include <string>
#ifndef BST_H
#define BST_H
using namespace std;

class BST;

class Node{
    private:
        int ip;
        Node* rightptr;
        Node* leftptr;
    public:
        Node(long long int ip);    
    friend class BST;
};

class BST{
    private:
        Node* head;
    public:
        BST();
        void createNode();
        void insertNode();
        void inorderTraversal();
        void search();
        void deleteNode();    
};

#endif