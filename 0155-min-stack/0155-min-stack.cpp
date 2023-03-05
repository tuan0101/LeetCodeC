class MinStack {
private:
    stack<int> myStack;
    stack<int> minStack;
public:    
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);       
        if(minStack.empty() || val<=getMin()) // include == bc it will pop this whenerve see this min_value
            minStack.push(val);
    }
    
    void pop() {     
        if(top() == getMin())
            minStack.pop(); 
        myStack.pop();
    }
    
    int top() {
        return myStack.empty()? NULL : myStack.top();
    }
    
    int getMin() {
        return minStack.empty()? NULL : minStack.top();
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