class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int temp = x;
        if(temp==INT_MIN)
        {
            return 0;
        }
        if(temp<0)
        {
            temp *= -1;
        }
        while(temp != 0)
        {
            if (ans>(INT_MAX-temp%10)/10)
            {
                return 0;
            }
            ans = ans*10 + temp%10;
            temp = temp/10;            
        }
        if(x<0)
        {
            ans *= -1;
        }
        return ans;
        
    }
};
