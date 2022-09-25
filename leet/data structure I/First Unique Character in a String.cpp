class Solution {
public:
    int firstUniqChar(string s) {
        
        int ans = -1;
        string ans2 = "";
        string so = s;
        sort(so.begin(),so.end());
        
        int i=0;
        int j=i+1;
        
        //making string which contains all letters without repetition
        while(j<s.length() || i<s.length())
        {
            if(so[i] == so[j])
            {
                while(so[i]==so[j])
                {
                    i++;
                    j++;
                }
                i++;
                j++;
            }
            else
            {
                ans2 += so[i];
                i++;
                j=i+1;
            }            
        }
        
        if(ans2.length()<1)
        {
            return ans;
        }
        
        //checking if s[k] is in ans2
        for(int k=0; k<s.length();k++)
        {
            if(ans2.find(s[k]) != string::npos)
            {
                ans = k;
                break;
            }
        }
        
        
        cout<<ans2;
        
        return ans;
    }
};
