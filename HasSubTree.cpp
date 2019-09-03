/**
 * 判断B树是不是A的子树
 * 本质上树的中序遍历，判断函数是--判断两个树是否相等的变形
 */
struct BinaryTreeNode{
    double              m_dbValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};

bool equalDouble(double a, double b){
    if((a-b>-0.0000001)&&(a-b<0.0000001))
        return true;
    else
        return false;
}

bool tree1HasTree2(BinaryTreeNode* tree1, BinaryTreeNode* tree2){
    if(tree2 == nullptr)
        return true;
    if(tree1 == nullptr)
        return false;
    if(!equalDouble(tree1->m_dbValue,tree2->m_dbValue))
        return false;
    return tree1HasTree2(tree1->m_pLeft,tree2->m_pLeft)&&tree1HasTree2(tree1->m_pRight,tree2->m_pRight);
    return false;
}

bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if(pRoot1!= nullptr&&pRoot2!= nullptr){
        if(equalDouble(pRoot1->m_dbValue,pRoot2->m_dbValue))
            result=tree1HasTree2(pRoot1,pRoot2);
        if(!result)
            result = tree1HasTree2(pRoot1->m_pLeft,pRoot2);
        if(!result)
            result = tree1HasTree2(pRoot1->m_pRight, pRoot2);
    }
    return result;
}
