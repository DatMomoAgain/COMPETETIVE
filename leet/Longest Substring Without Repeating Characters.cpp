class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len ==0 || len==1)
        {
            return len;
        }
        int ans=1;
        int c=0;
        //map<char,int> m;
        for(int i=0; i<len; i++)
        {
            map<char,int> m;
            for(int j=0; j<len-i;j++)
            {
                m[s[i+j]]++;
                if(m[s[i+j]]>1)
                {
                    break;
                }
                c++;
                if (ans<c)
                {
                    ans = c;
                }
            }
            c=0;
        }
        
        return ans;
    }
};
