class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int q = matrix[0].size()-1;
        int lc=-1;
        for(int i=0; i<matrix.size(); i++)
        {
            if(matrix[i][q]>=target)
            {
                lc = i;
                break;
            }
            //else if()
        }
        if(lc == -1)
        {
            return false;
        }
        vector<int>::iterator it;
        it = find(matrix[lc].begin(), matrix[lc].end(), target);
        if(it != matrix[lc].end())
        {
            return true;
        }
        return false;
        
    }
};
