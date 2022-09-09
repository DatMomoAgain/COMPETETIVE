class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        vector<int> col;
        int x =1;
        
        for(int i=0; i<numRows; i++)
        {
            for(int j =0; j< i+1; j++)
            {
                if(j>0 && j <i)
                {
                    x = ans[i-1][j-1] + ans[i-1][j];
                }
                else
                {
                    x = 1;
                }
                col.push_back(x);
            }
            ans.push_back(col);
            col = {};
        }
        
        return ans;
        
    }
};
