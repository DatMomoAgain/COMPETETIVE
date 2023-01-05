class Solution {
public:
    string addStrings(string num1, string num2) {

        //swapping
        if(num1.size()<num2.size())
        {
            string s = num2;
            num2 = num1;
            num1 = s;
        }

        string ans="";
        int carry=0;
        int j=0;

        //loop till size of smaller no.
        for(int i=num2.size()-1; i>=0; i--)
        {
            j = i+(num1.size()-num2.size());
            int n1 = num1[j] - '0';
            int n2 = num2[i] - '0';
            int n3 = n1+n2+carry;
            carry=0;
            if(n3>=10)
            {
                n3%=10;
                carry++;
            }
            char c = n3 + '0';
            ans = c + ans;
        }

        //adding remaining digits of larger no.
        while(j!=0)
        {
            j--;
            int n1 = num1[j] - '0';
            int n3 = n1+carry;
            carry=0;
            if(n3>=10)
            {
                n3%=10;
                carry++;
            }
            char c = n3 + '0';
            ans = c + ans;
        }

        if(carry==1)
        {
            ans = "1" + ans;
        }

        return ans;
    }
};
