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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> nodes;
        TreeNode* temp = root;
        
        if(root==NULL)
        {
            return ans;
        }
        
        //push root value
        ans.push_back(temp->val);
        
        while(temp->right!=NULL || temp->left!=NULL || nodes.size()!=0)
        {
            //go left
            if(temp->left!=NULL)
            {
                //store nodes where you can go right but went left
                if(temp->right!=NULL)
                {
                    nodes.push_back(temp->right);
                }
                temp = temp->left;
                ans.push_back(temp->val);
            }
            //go right
            else if(temp->right!=NULL)
            {
                temp = temp->right;
                ans.push_back(temp->val);
            }
            //if you reach a leaf go to node where you could go right but went left
            else if(nodes.size()!=0)
            {
                temp = nodes[nodes.size()-1];
                nodes.pop_back();
                ans.push_back(temp->val);
            }
        }
        
        return ans;
    }
};
