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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans=0;
        vector<int> v;
        if(root==NULL)
        {
            return false;
        }
        sum(root, ans, targetSum, v);
        if(v.size()!=0)
        {
            return true;
        }
        return false;
    }

    void sum(TreeNode* root, int &ans, int target, vector<int> &v)
    {
        if(root)
        {
            ans+=root->val;
            sum(root->left, ans, target, v);
            if(root->right==NULL && root->left==NULL && ans==target)
            {
                v.push_back(ans);
            }
            sum(root->right, ans, target, v);
            ans-=root->val;
        }
    }
};
