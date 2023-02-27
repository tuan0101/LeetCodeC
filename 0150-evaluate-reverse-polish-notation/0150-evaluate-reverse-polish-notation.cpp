class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //90% 75%
        stack<int> q;
        
        for(string &s : tokens){
            if (s.size()>1 || isdigit(s[0])) // size > 1 check for negative number
                q.push(stoi(s));
            else{
                int x2  = q.top(); q.pop();
                int x1 = q.top(); q.pop();
                switch(s[0]) { // unlike string, char is bit comparision
                    case '+': x1+=x2; break;
                    case '-': x1-=x2; break;
                    case '*': x1*=x2; break;
                    case '/': x1/=x2; break;
                }
                q.push(x1);
            }               
        }
        return q.top();
    }
};

// can replace switch case here by advance map function
// unordered_map<string, function<int (int, int) > > map = {
//             { "+" , [] (int a, int b) { return a + b; } },
//             { "-" , [] (int a, int b) { return a - b; } },
//             { "*" , [] (int a, int b) { return a * b; } },
//             { "/" , [] (int a, int b) { return a / b; } }
//         };