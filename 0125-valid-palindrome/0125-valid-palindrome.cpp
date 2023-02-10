class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int left = 0, right = len-1;
        while (left < right){
            
            if(!iswalnum(s[left])) left++;
            else if(!iswalnum(s[right])) right--;
            else if(tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};