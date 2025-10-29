#include <string>
#ifndef BST_H
#define BST_H
using namespace std;

class BST;

class Node{
    private:
        int a,b,c,d;
        class Node* nextptr;
    public:
        Node(string& ip);    
    friend class BST;
};

class BST{
    
};

#endif