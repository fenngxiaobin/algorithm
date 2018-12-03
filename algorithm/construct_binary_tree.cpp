#include <iostream>
#include <stack>
#include <exception>
using std::clog;
using std::endl;

struct BinaryTreeNode{
    int                 n_value;
    BinaryTreeNode*     l_child;
    BinaryTreeNode*     r_child;
};

BinaryTreeNode* ConstructCore(int* start_preorder,int* end_preorder, int* start_inorder, int* end_inorder);
/**
 * construct a binary tree from the preorder sequence and inorder sequence
 * conditions: the sequence don not contains the same element
 * @param preorder
 * @param inorder
 * @param length
 * @return
 */
BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
    if(preorder== nullptr||inorder== nullptr||length<=0){
        return nullptr;
    }
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* start_preorder,int* end_preorder, int* start_inorder, int* end_inorder){
    int root_value=start_preorder[0];
    BinaryTreeNode* root=new BinaryTreeNode();
    root->n_value=root_value;
    root->l_child= nullptr;
    root->r_child = nullptr;
    //the stop condition
    if(start_preorder==end_preorder){
        if(start_preorder==end_preorder&&*start_preorder==*start_inorder){
            return root;
        }
        else{
            clog<<"invalid input"<<endl;
            throw std::exception();
        }
    }
    int* root_inorder = start_inorder;
    while(*root_inorder!=root_value&&root_inorder<=end_inorder){
        ++root_inorder;
    }
    if(*root_inorder!=root_value&&root_inorder==end_inorder){
        clog<<"invalid input"<<endl;
        throw std::exception();
    }

    int left_length=root_inorder-start_inorder;
    int* left_pre_order=start_preorder+left_length;
    if(left_length>0){
        root->l_child=ConstructCore(start_preorder+1,left_pre_order,start_inorder,root_inorder-1);
    }
    if(left_length+start_preorder<end_preorder){
        root->r_child=ConstructCore(left_pre_order+1,end_preorder,root_inorder+1,end_inorder);
    }
}


int main() {

    return 0;
}