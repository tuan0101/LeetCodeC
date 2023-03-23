class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        int base = 0;
        const int LAST_INT_MAX_DIGIT = INT_MAX%10;
        while (i < n && s[i] == ' '){
            i++;
        }
        
        if(s[i] == '-'){
            sign = -1; i++;
        }else if (s[i] == '+'){
            sign = 1; i++;
        }
        
        //check overfloat
        // 2^31-1 = 2147483647 = INT_MAX
        // -2^31 = -2147483648 = INT_MIN
        // if current base > 214748364 then add any number after base will overfloat
        while(i < n && isdigit(s[i]))
        {
            int currentDigit = (s[i]-'0');
            
            if(base > INT_MAX/10 || (base == (INT_MAX/10) && currentDigit > LAST_INT_MAX_DIGIT)){
                 return (sign == 1)? INT_MAX : INT_MIN;
            }
            base = base*10 + currentDigit;
            i++;
        }
        
        if (sign == 1) return base;
        else return -base;
    }
};

