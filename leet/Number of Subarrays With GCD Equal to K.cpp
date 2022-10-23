class Solution {
public:    
    
    //First 2 function find gcd of a vector
    int g2cd(int n1, int n2)
    {
      if (n1 == 0)
        return n2;
      return g2cd(n2 % n1, n1);
    }
    
    int gcd(vector<int> num)
    {
        sort(num.begin(), num.end());
        int ans = num[0];
        for(int i=0; i<num.size()-1; i++)
        {
            ans = g2cd(num[i+1],ans);
            if(ans==1)
            {
                return 1;
            }
        }
        return ans;
    }
    
    //MAIN FUNCTION
    int subarrayGCD(vector<int>& nums, int k) {
        int i=0;
        int c=0;
        int dist=0;
        
        while(i<nums.size())
        {
            vector<int> temp;
            if(nums[i]%k==0)
            {
                //temp vector stores consecutive numbers which are divisible by k
                int i2=i;
                while(i2<nums.size() && nums[i2]%k==0)
                {
                    temp.push_back(nums[i2]);
                    //if number = k then count increases
                    if(nums[i2]==k)
                    {
                        c++;
                    }
                    i2++;
                }
                //now we check invalid subarrays in temp
                if(temp.size()>1 && gcd(temp)==k)
                {
                    //c if there are no invalid subarrays
                    c+=(temp.size()-1)*(temp.size())/2;
                    int j=0;
                    while(j<temp.size()-1)
                    {
                        //temp2 stores consecutive numbers inside temp whose gcd is not k
                        vector<int> temp2;
                        if(g2cd(temp[j],temp[j+1]) != k)
                        {
                            temp2.push_back(temp[j]);
                            temp2.push_back(temp[j+1]);
                            int j2=j+2;
                            while(j2<temp.size() && gcd(temp2)!=k)
                            {
                                temp2.push_back(temp[j2]);
                                j2++;
                            }
                            //there is chance that last element makes it so that gcd is k, so we check that and remove it if thats the case
                            if(gcd(temp2)==k)
                            {
                                temp2.pop_back();
                            }
                            j = j2-2;
                            
                            //now we remove invalid subarrays 
                            c-= (temp2.size()-1)*(temp2.size())/2;
                        }
                        j++;
                    }
                }
                i = i2-1;
            }
            
            i++;
        }
        
        return c;
        
    }
};
