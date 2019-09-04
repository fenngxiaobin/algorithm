/** 
 * 二叉树层序遍历  队列
 */

void printLevelBinary(BinaryTreeNode* root)
{
    if(!root)
        return;
    std::deque<BinaryTreeNode*> deque1;

    deque1.push_back(root);
    while(deque1.size()){
        BinaryTreeNode* pNode = deque1.front();
        deque1.pop_front();
        //print("");
        if(pNode->m_pLeft)
            deque1.push_back(pNode);
        if(pNode->m_pRight)
            deque1.push_back(pNode);
    }
}
