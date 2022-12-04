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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        //base cases if root is empty or has no children
        if(root==NULL)
        {
            return ans;
        }
        else if(root->left==NULL && root->right == NULL)
        {
            vector<int> t3;
            ans.push_back(t3);
            ans[0].push_back(root->val);
            return ans;
        }
        
        
        TreeNode* temp = root;
        vector<TreeNode*> back; //node at which temp should go back when leaf is reached
        vector<int> back_lvl; //level of node in back vector
        int i=0; //for tracking level
        int c=0; 

        while(back.size()!=0 || temp->left!=NULL || temp->right!=NULL || c!=0)
        {
            c=0;
            
            //adding empty vector to ans vector
            vector<int> temp2;
            if(i>=ans.size())
            {
                ans.push_back(temp2);
            }
            
            ans[i].push_back(temp->val);
            
            if(temp->left !=NULL)
            {
                //store node in back if it has right child
                if(temp->right!=NULL)
                {
                    back.push_back(temp);
                    back_lvl.push_back(i);
                }
                temp = temp->left;
                c++;
            }
            else if(temp->right !=NULL)
            {
                temp = temp->right;
                c++;
            }
            else
            {
                if(back.size()==0)
                {
                    break;
                }
                
                //go to node in back and then to its right child
                temp = back[back.size()-1];
                back.pop_back();
                i = back_lvl[back_lvl.size()-1];
                back_lvl.pop_back();
                c++;
                temp = temp->right;
            }
            i++;
        }
        
        return ans;
    }
    
    
};
