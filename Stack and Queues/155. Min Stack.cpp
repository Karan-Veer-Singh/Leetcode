class MinStack {
public:
    stack<long long> stk;
    long long mini;
    
    MinStack() {
        while(!stk.empty())
            stk.pop();
        
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
        
        if(stk.empty())
        {
            mini = value;
            stk.push(value);
        }
        else if(value < mini)
        {
            stk.push(2*value-mini);
            mini = value;
        }
        else
        {
            stk.push(value);
        }    
    }
    
    void pop() {
        if(stk.empty())
            return;
        
        long long value = stk.top();
        stk.pop();
        
        if(value < mini)
            mini = 2*mini-value;
        
    }
    
    int top() {
        if(stk.empty())
            return -1;
        
        long long value = stk.top();
        
        if(value < mini)
            return mini;
        else
            return value;
        
    }
    
    int getMin() {
        return mini;
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
 
 // https://leetcode.com/problems/min-stack/submissions/
