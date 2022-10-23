class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int,int> m;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                ans.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                break;
            }
        }
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        int sum2 = (nums.size()+1)*(nums.size()+2)/2;
        ans.push_back(sum2-sum);
        
        
        return ans;        
    }
};
