#include <iostream>
#include <stack>
#include <exception>
using std::clog;
using std::endl;


struct BinaryTreeNode{
    BinaryTreeNode* l_child;
    BinaryTreeNode* r_child;
    BinaryTreeNode* parent;
};

/**
 * find the the next element belong the Inorder Sequence
 * @param node
 * @return
 */
BinaryTreeNode* GetInorderNext(BinaryTreeNode* node){
    if(node== nullptr){
        return nullptr;
    }
    BinaryTreeNode* next= nullptr;
    //3 kinds
    if(node->r_child!= nullptr){
        BinaryTreeNode* p_right=node->r_child;
        while (p_right->l_child!= nullptr){
            p_right=p_right->l_child;
        }
        next = p_right;
    }else if(node->parent!= nullptr){
        BinaryTreeNode* parent= node->parent;
        BinaryTreeNode* p_current=node;
        while (parent!= nullptr&&parent->r_child==p_current){
            p_current=parent;
            parent=p_current->parent;
        }
        next=parent;
    }


    return next;
}


int main() {

    return 0;
}