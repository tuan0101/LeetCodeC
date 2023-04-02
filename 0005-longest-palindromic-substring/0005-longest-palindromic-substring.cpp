class Solution {
private:
    string result;
    int length = 0;
public:
    string longestPalindrome(string s) {
        for(int i=0; i<s.size(); i++){
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i+1);
        }
        return result;
    }
    
    void checkPalindrome(string s, int l, int r){
        while(l>=0 && r<s.size() && s[l] == s[r]){
            string currentPal = s.substr(l, r-l+1);
            if(currentPal.size() > length){
                result = currentPal;
                length = currentPal.size();
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