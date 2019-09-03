bool isSymmertrical(BinaryTreeNode* tree1,BinaryTreeNode* tree2)
{
    if(tree1 == nullptr&&tree2== nullptr)
        return true;
    if(tree1== nullptr||tree2== nullptr)
        return false;
    if(tree1->m_dbValue!=tree2->m_dbValue)
        return false;
    return isSymmertrical(tree1->m_pLeft,tree2->m_pRight)&&isSymmertrical(tree1->m_pRight,tree2->m_pLeft);
}

/**
 * 判断二叉树是否是镜像
 * 把树复制一份来看看
 */
 
bool isSymmertrical(BinaryTreeNode* tree)
{
    return isSymmertrical(tree,tree);
}
