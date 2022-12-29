class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i1=0;
        int i2 =m-1;


        while(i1!=n && i2!=-1)
        {
            //target found
            if(matrix[i1][i2]==target)
            {
                return true;
            }

            if(target<matrix[i1][i2])
            {
                i2--;
            }
            else if(target>matrix[i1][i2])
            {
                i1++;
            }
        }
        return false;
    }
};
