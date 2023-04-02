class Solution {
private:
    string result;
    int length = 0;
public:
    string longestPalindrome(string s) {
        // for(int i=0; i<s.size(); i++){
        //     checkPalindrome(s, i, i);
        //     checkPalindrome(s, i, i+1);
        // }
        // return result;
        //if(s.size() < 2) return s;
        int max_len = 0;
        int start_idx = 0;
        int i = 0;
        while(i < s.size()) {
            int r_ptr = i; 
            int l_ptr = i;
            //find the middle of a palindrome
            while(r_ptr < s.size()-1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
            i = r_ptr+1;
            //expand from the middle out
            while(r_ptr < s.size()-1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
                r_ptr++;
                l_ptr--;
            }
            int new_len = r_ptr - l_ptr + 1;
            if(new_len > max_len) {
                start_idx = l_ptr;
                max_len = new_len;
            }
        }
        return s.substr(start_idx, max_len);
    }
    
    // 56% 17%
    void checkPalindrome(string s, int l, int r){
        while(l>=0 && r<s.size() && s[l] == s[r]){
            if(r-l+1 > length){
                result = s.substr(l, r-l+1);
                length = r-l+1 ;
            }
            l--;
            r++;                
        }
    }
    
    
};



// s = "babad"
// 01
// babad
// dp[1] = 1
// dp[2] = 1
// dp[3 = 