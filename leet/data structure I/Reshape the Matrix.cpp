class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> ans;        
        vector<int> col; 
        
        int legal = 0; 
        
        if (r*c == rows*columns)
        {
            legal = 1;
        }
        if (legal == 0)
        {
            return mat;
        }
        
        int q = 0;
        int w = 0;
        
        for (int i=0; i<r; i++)
        {
            for(int j =0; j<c; j++)
            {
                col.push_back(mat[q][w]);
                w+=1;
                if(w>=columns)
                {
                    w = 0;
                    q +=1;
                }
            }
            ans.push_back(col);
            col = {};
        }
        
        
            return ans;
        
        
    }
};
