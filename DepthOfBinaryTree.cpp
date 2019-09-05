struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}

//递归求深度
int DepthRecurse(BinaryTreeNode* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    return DepthRecurse(root->m_pLeft)>DepthRecurse(root->m_pRight)?(DepthRecurse(root->m_pLeft)+1):(DepthRecurse(root->m_pRight)+1);
}

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};
