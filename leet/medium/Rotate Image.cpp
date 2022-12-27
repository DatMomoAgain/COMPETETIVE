class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n2 = n;
        int c=0;
        while(n!=0){
            for(int i=c; i<n-1;i++)
            {
                int t;
                int t2;
                //putting 1st row in last column
                t = matrix[i][n-1];
                matrix[i][n-1] = matrix[c][i];
                //putting 1st column in 1st row
                matrix[c][i] = matrix[n2-1-i][c];
                //putting last column in last row
                t2 = matrix[n-1][n2-1-i];
                matrix[n-1][n2-1-i] = t;
                //putting last row in 1st column
                matrix[n2-1-i][c] = t2;
            }
            
            //as this happens, operation shifts to inner border(will shift to 2x2 matrix in case of 4x4)
            c++;
            n--;
        }
    }
};
