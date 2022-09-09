class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator itr;
        vector<int> q;
        
        if (nums1.size() > nums2.size())
        {
            for(int i =0; i< nums1.size(); i++)
            {
                itr = find(nums2.begin(), nums2.end(), nums1[i]);
                if (itr != nums2.end())
                {
                    q.push_back(nums2[itr - nums2.begin()]);
                    nums2.erase(itr);
                }
            }
        }
        else
        {
            for(int i =0; i< nums2.size(); i++)
            {
                itr = find(nums1.begin(), nums1.end(), nums2[i]);
                if (itr != nums1.end())
                {
                    q.push_back(nums1[itr - nums1.begin()]);
                    nums1.erase(itr);
                }
            }
        }
        
        return q;
        
    }
};
