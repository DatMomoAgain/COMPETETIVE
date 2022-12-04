/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int* i = new int();
        *i = 0;
        int* max = new int();
        *max=0;
        traverse(root,*i, *max);
        return *max;
    }
    
    void traverse(TreeNode* root, int &i, int &max)
    {
        if(root)
        {
            i++;
            if(i>max)
                max = i;
            traverse(root->left, i, max);
            traverse(root->right, i, max);
            i--;
        }
        
    }
};
