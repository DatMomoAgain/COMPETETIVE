class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentd = prices[0];
        int ans = 0;
        for(int i=0; i<prices.size()-1; i++)
        {
            if (prices[i] < currentd)
            {
                currentd = prices[i];
            }
            if (prices[i+1] - currentd > ans)
            {
                ans = prices[i+1] - currentd;
            }
        }
        
        return ans;
    }
};
