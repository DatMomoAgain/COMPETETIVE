class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int ci= INT_MIN;
        int cj= INT_MIN;

        for(int i=0; i<nums.size(); i++)
        {
            //if next no. is same as prev one, skip it to avoid duplicates
            if(nums[i]==ci)
                continue;
            for(int j=i+1; j<nums.size(); j++)
            {
                //if next no. is same as prev one, skip it to avoid duplicates
                if(nums[j]==cj)
                    continue;

                //target to find
                int f = 0-(nums[i]+nums[j]);
                int index = binary(nums,j+1, f);

                //if target is found
                if(index!=-1)
                {
                    vector<int> trip = {nums[i], nums[j], nums[index]};
                    ans.push_back(trip);
                }
                cj = nums[j];
            }
            ci = nums[i];
        }

        //old method to remove duplicates...takes lot of time
        /*sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());*/

        return ans;       
    }


    //binary search because built in function takes linear time complexity
    //PARAMETERS: vector, index from where we want to start search to avoid duplicates, target
    int binary(vector<int> &v, int r, int f)
    {
        int l = v.size()-1;
        int m = (r+l)/2;
        while(r<=l)
        {
            m = (r+l)/2;
            if(f>v[m])
            {
                r=m+1;
            }
            else if(f<v[m])
            {
                l = m-1;
            }
            else
            {
                return m;
            }
        }

        return -1;
    }
};
