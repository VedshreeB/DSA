class MinStack {
    stack<pair<int,int>> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int mini;
        if(stk.empty()) mini=  val;
        else mini= min(val,stk.top().second);
        stk.push({val,mini});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;    
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