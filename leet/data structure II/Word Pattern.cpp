class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> pat;
        vector<string> v;
        string word="";

        //pushing all words of string into vector 
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=' ')
            {
                word += s[i];
            }
            else
            {
                v.push_back(word);
                word="";
            }
        }
        if(word!="")
            v.push_back(word);

        if(pattern.size()!=v.size())
            return false;
        
        for(int i=0; i<pattern.size(); i++)
        {
            if(pat.find(pattern[i])!=pat.end())
            {
                if(pat[pattern[i]]!=v[i])
                    return false;
            }
            else
            {
                for(auto x : pat)
                {
                    if(v[i]==x.second)
                        return false;
                }
            }
            pat[pattern[i]] = v[i];
        }
        return true;
    }
};
