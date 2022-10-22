class Solution {
public:
    string removeDigit(string number, char digit) {
        int ind = number.size();
        string temp1 = number;
        string temp2 = number;
        string max = number;
        for(int i=0; i<ind;i++)
        {
            if(temp2[i]==digit)
            {
                temp2.erase(temp2.begin()+i);
                max = temp2;
                for(int j=i; j<ind; j++)
                {
                    if(temp1[j]==digit)
                    {
                        temp1.erase(temp1.begin()+j);
                    }
                    if (temp1>max && temp1 != number)
                    {
                        max = temp1;
                    }
                    temp1 = number;
                }
                break;
            }
        }
        return max;
        
    }
};
