class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> s1;
        map<char,int> t1;
        if(s.length() != t.length())
        {
            return false;
        }
        for(char &c:s)
        {
            s1[c]++;
        }
        for(char &c:t)
        {
            t1[c]++;
        }
        for(auto i:s1)
        {
            if(s1[i.first]!=t1[i.first])
            {
                return false;
            }
        }
        return true;        
    }
};
