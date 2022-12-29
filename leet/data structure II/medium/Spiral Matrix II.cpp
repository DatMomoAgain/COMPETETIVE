class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int n1 = n;

        //base case
        if(n==1)
        {
            ans[0][0]=1;
            return ans;
        }

        int i1=0;
        int j1=0;
        int c=0;
        int c2=0;

        while(c<=n1*n1-1){

            if(n==1){
                ans[c2][c2]=c+1;
                c++;
            }

            for(int i=0; i<4*(n-1); i++)
            {
                if(i<=n-1)
                {
                    ans[c2][i1]=c+1;
                    i1++;
                    if(i1==n+c2)
                        i1=1+c2;
                }
                else if(i<=2*(n-1))
                {
                    ans[i1][n-1+c2] = c+1;
                    i1++;
                    if(i1==n+c2)
                        i1=n-2+c2;
                }
                else if(i<=3*(n-1))
                {
                    ans[n-1+c2][i1]=c+1;
                    i1--;
                    if(i1==-1+c2)
                        i1=n-2+c2;
                }
                else
                {
                    ans[i1][c2]=c+1;
                    i1--;
                }
                //cout<<ans[1][0]<<' ';
                c++;
            }
            n-=2;
            c2++;
            i1=c2;
        }
        return ans;
    }
};
