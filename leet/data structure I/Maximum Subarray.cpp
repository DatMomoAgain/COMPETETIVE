class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max = nums[0];
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if (nums[i] < sum+nums[i])
            {
                sum += nums[i]; 
            }
            else
            {
                sum = nums[i];
            }
            if (max < sum)
            {
                max = sum;
            }
        }
        
        return max;
    }
};
