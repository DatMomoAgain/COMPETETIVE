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
    bool isSymmetric(TreeNode* root) {
        vector<int> left; 
        vector<int> right;

        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            return false;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            return false;
        }
        preorderL(root->left, left);
        preorderR(root->right, right);

        if(left.size()!=right.size())
        {
            return false;
        }
        else
        {
            cout<<"left: ";
            for(int i=0; i<left.size(); i++){
                cout<<left[i]<<' ';
            }
            cout<<endl;
            cout<<"right: ";
            for(int i=0; i<left.size(); i++){
                cout<<right[i]<<' ';
            }
            for(int i=0; i<left.size(); i++)
            {
                if(left[i] != right[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void preorderL(TreeNode* root, vector<int> &v)
    {
        if(root)
        {
            v.push_back(root->val);
            preorderL(root->left, v);
            preorderL(root->right, v);
        }
        else
        {
            v.push_back(-200);
        }
    }

    void preorderR(TreeNode* root, vector<int> &v)
    {
        if(root)
        {
            v.push_back(root->val);
            preorderR(root->right, v);
            preorderR(root->left,v);
        }
        else
        {
            v.push_back(-200);
        }
    }
};
