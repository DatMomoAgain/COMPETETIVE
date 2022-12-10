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
    bool isValidBST(TreeNode* root) {

        TreeNode* temp = root;
        vector<TreeNode*> v;
        vector<int> vals;

        while(temp->left!=NULL || temp->right!=NULL || v.size()!=0)
        {
            vals.push_back(temp->val);
            if(!search(root, temp->val))
            {
                cout<<temp->val;
                return false;
            }
            //traversing begins
            if(temp->left)
            {
                if(temp->right)
                {
                    v.push_back(temp->right);
                }
                temp = temp->left;
            }
            else
            {
                if(temp->right)
                {
                    temp = temp->right;
                }
                else{
                    temp = v[v.size()-1];
                    v.pop_back();
                }
            }
            //traversing ends 
        }
        vals.push_back(temp->val);
        sort(vals.begin(),vals.end());
        for(int i=0; i<vals.size()-1;i++)
        {
            if(vals[i]==vals[i+1])
            {
                return false;
            }
        }
        if(!search(root, temp->val)){
            cout<<"last";
            return false;}
        return true;
    }

    bool search(TreeNode* root, int val)
    {
        TreeNode* temp = root;
        while(temp->left!=NULL || temp->right!=NULL)
        {
            if(temp->val>val)
            {
                if(temp->left)
                    temp = temp->left;
                else
                    return false;
            }
            else if(temp->val<val)
            {
                if(temp->right)
                    temp = temp->right;
                else
                    return false;
            }
            else
            {
                return true;
            }
        }
        if(temp->val==val)
            return true;
        return false;
    }
};
