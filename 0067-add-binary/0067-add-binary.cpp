class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int carry = 0, sum = 0; 
        string result;
        
        while(i>=0 || j >= 0){
            sum = carry;
            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';
            result += sum%2 + '0'; // remainder of sum divided by 2
            // or
            // result += to_string(sum%2);
            carry = (sum>1)? 1 : 0;
        }
        if(carry==1) result += carry + '0'; // + '0' is push_back O(1)
        reverse(result.begin(), result.end());
        return result;
    }
};


// 11
// 01
// 100
// sum =1+1=2 => s="1"
// sum 0:0 1:1 2:0 3:1