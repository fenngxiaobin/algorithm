/**
 * 二叉树翻转，本质上是交换两个子节点 
 * 属于树的前序遍历，终止条件：两个节点都为空
 */
void mirror(BinaryTreeNode* tree)
{
    if(tree == nullptr)
        return nullptr;
    if(tree->m_pLeft== nullptr&&tree->m_pRight== nullptr)
        return;
    BinaryTreeNode *pTemp = tree->m_pRight;
    tree->m_pRight = tree->m_pLeft;
    tree->m_pLeft = pTemp;
    
    if(tree->m_pLeft){
        mirror(tree->m_pLeft);
    }
    if(tree->m_pRight){
        mirror(tree->m_pRight);
    }
}
