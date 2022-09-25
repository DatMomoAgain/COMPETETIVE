class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> rans;
        map<char,int> mag;
        for(char c: ransomNote)
        {
            rans[c] += 1;
        }
        for(char c: magazine)
        {
            mag[c] += 1;
        }
        for(auto i:rans)
        {
            if (rans[i.first] > mag[i.first])
            {
                return false;
            }
        }
        return true;
        
    }
};
