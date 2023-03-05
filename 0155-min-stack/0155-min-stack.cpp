class MinStack {
private:
    // 2 stacks: 40% 75%
    stack<int> myStack;
    int min_value = INT_MAX;
public:    
    MinStack() {
        
    }
    
    void push(int val) {              
        if(val <= min_value){            
            myStack.push(min_value);
            min_value = val;
        }
        myStack.push(val); 
           
    }
    
    void pop() {     
        if(top() == min_value){
            myStack.pop(); 
            min_value = top();
        }
        myStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return min_value;;
    }
};

// 3    5   2   4   1
// 3       2        1
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */