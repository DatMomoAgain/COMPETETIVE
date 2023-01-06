class MinStack {
public:
    int t;
    int m;
    int arr[7500];
    int arrm[500];
    MinStack() {
        t =-1;
        m=-1;
    }
    
    void push(int val) {
        if(t==-1)
        {
            arr[0] = val;
            arrm[0] = val;
            t++;
            m++;
        }
        else
        {
            t++;
            arr[t] = val;
            if(val<=getMin())
            {
                m++;
                arrm[m] = val;
            }
        }
    }
    
    void pop() {
        if(arr[t]==getMin())
            m--;
        t--;
        
    }
    
    int top() {
        return arr[t];
        
    }
    
    int getMin() {
        return arrm[m];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
