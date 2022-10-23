class Solution {
public:
    double myPow(double x, int n) {
        if (n<0)
        {
            x = 1/x;
            if(n!=INT_MIN)
            {
                n *= -1;
            }
            else if(x!=-1)
            {
                n +=1;
                n *=-1;
            }
        }
        if(n==0)
        {
            return 1;
        }
        else if(x<1 && x>0 && n==INT_MAX)   
        {
            return 0;
        }
        else if(x==1)
        {
            return 1;
        }
        else if(x==-1)
        {
            if (n%2==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        if(n==1)
        {
            return x;
        }
        else
        {
            return x*myPow(x, n-1);
        }
        
    }
};
