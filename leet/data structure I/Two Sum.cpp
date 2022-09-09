class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        int t;
        vector<int>::iterator p;
        int j;
        for(int i = 0; i<nums.size(); i++)
        {
            t = target - nums[i];
            j = i;
            p = find(nums.begin(), nums.end(), t);
            if (p != nums.begin() + nums.size() && p != nums.begin() + i)
            {
                break;
            }
        }
        int k = p - nums.begin();
        vector<int> ans = {j, k};
        return ans;
        //cout << "[" << j << ',' << p - nums.begin() << ']';
        
    }
};
