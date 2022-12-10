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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        traverse(root, vals);

        for(int i=0; i<vals.size(); i++)
        {
            if(binary(vals, k-vals[i]))
            {
                if(vals[i]==k-vals[i]){
                    continue;}

                return true;
            }
        }

        return false;
    }

    void traverse(TreeNode* root, vector<int> &vals)
    {
        if(root)
        {
            traverse(root->left, vals);
            vals.push_back(root->val);
            traverse(root->right ,vals);
        }
    }

    bool binary(vector<int> vals, int k)
    {
        int l = 0;
        int r = vals.size() -1;
        int m= (l+r)/2;
        while(l<r)
        {
            if(vals[m]==k)
            {
                return true;
            }
            else if(vals[m]>k)
            {
                r = m-1;
                m = (r+l)/2;
            }
            else
            {
                l = m+1;
                m = (r+l)/2;
            }
        }
        if(vals[m]==k)
            return true;
        return false;

    }
};
