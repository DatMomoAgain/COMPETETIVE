class Solution {
public:
    char corr(char c)
    {
        if(c == '('){
            return ')';
        }
        if(c == '['){
            return ']';
        }
        if(c == '{'){
            return '}';
        }
        if(c == ')'){
            return '(';
        }
        if(c == ']'){
            return '[';
        }
        if(c == '}'){
            return '{';
        }
        cout<<"erreo";
        return 'e';
    }
    
    bool open(char c)
    {
        if(c=='(' || c=='[' || c=='{')
        {
            return true;
        }
        return false;
    }
    
    bool close(char c)
    {
        if(c=='(' || c=='[' || c=='{')
        {
            return false;
        }
        return true;
    }
    
    bool isValid(string s) {
        vector<char> brac(s.begin(),s.end());
        vector<char>::iterator it = brac.begin();
        while(brac.size()!=0)
        {
            int b1 =0;
            int b2 =0;
            if(close(brac[0]))
            {
                return false;
            }
            while(open(brac[b2]))
            {
                b2++;
                b1++;
                if(b2>=brac.size())
                {
                    return false;
                }
            }
            b1--;
            cout<<b1<<b2;
            cout<<' ';
            if(brac[b1] == corr(brac[b2]))
            {
                brac.erase(it+b2);
                brac.erase(it+b1);
            }
            else
            {
                cout<<"2e";
                return false;
            }
        }
        
        return true;
    }
};
