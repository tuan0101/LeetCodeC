class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (auto ch : s) {
            if(ch == '{'){
                myStack.push('}');
            }
            else if(ch == '(')
                myStack.push(')');
            else if(ch == '[')
                myStack.push(']');       
            else{
                if(myStack.empty() || myStack.top() != ch)
                    return false;
                else
                    myStack.pop();
            }
        }
        return myStack.empty();
    }
};

// {[]};

// myStack: 
// open bracket: add to stack
// close bracket: 
//      if match: remove, next
//      if not: return false;

// {}]) : the stack is empty before finish the loop