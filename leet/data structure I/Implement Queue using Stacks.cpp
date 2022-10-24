class MyQueue {
public:
    int arr1[101];
    int arr2[101];
    int top=-1;
    int front=-1;
    
    void push(int x) {
        top++;
        arr1[top] = x;
        if (front==-1)
        {
            front++;
        }
    }
    
    int pop() {
        int ret = arr1[front];
        for(int i=0; i<top-front; i++)
        {
            arr2[i] = arr1[top-i];
        }
        front++;
        for(int i=front; i<top; i++)
        {
            arr1[i] = arr2[top-i];
        }        
        return ret;
    }
    
    int peek() {
        return arr1[front];        
    }
    
    bool empty() {
                if(top == -1 || front>top)
                {
                    return true;
                }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
