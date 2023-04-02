class Solution {
public:
    
    string longestPalindrome(string s) {
        int max_len = 0;
        int i=0;
        int start = 0;
        while(i < s.size()){
            int l = i, r = i;
            
            // by skipping duplicate char, no need to check odd or even palindrom
            while(r<s.size()-1 && s[r] == s[r+1]) r++;
            i = r+1;
            while(l>0 && r<s.size()-1 && s[r+1] == s[l-1]){
                l--; r++;
            }
            
            int new_len = r-l+1;
            if(new_len > max_len){
                max_len = new_len;
                start = l;
            }
        }
        return s.substr(start, max_len);
    }  
};



// s = "abbbbbad"
// 01
// babad
// dp[1] = 1
// dp[2] = 1
// dp[3 = 