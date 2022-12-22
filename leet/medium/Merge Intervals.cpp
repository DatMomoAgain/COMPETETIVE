class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return intervals;
            
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        int c=0;
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(ans[c][1]>=intervals[i][0])
            {
                vector<int> t;
                if(ans[c][1]<intervals[i][1])
                    t = {ans[c][0], intervals[i][1]};
                else
                    t = {ans[c][0], ans[c][1]};
                    
                ans.pop_back();
                ans.push_back(t);
            }
            else
            {
                ans.push_back(intervals[i]);
                c++;
            }
        }
        
        return ans;
    }
};
