class MyQueue {
public:
    stack<int> myStack;
    stack<int> myQueue;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        myStack.push(x);
    }
    
    int pop() {
        int result = peek();     
        myQueue.pop();
        return result;
    }
    
    int peek() {
        if(myQueue.empty()){
            while(!myStack.empty()){
                myQueue.push(myStack.top());
                myStack.pop();
            }
        }
        return myQueue.top();
    }
    
    bool empty() {
        return myStack.empty() && myQueue.empty();
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
