class Solution {
public:
    bool isAnagram(string s, string t) {
        int letters[26] = {0};
        int len = s.length();
        
        if(len != t.length()) return false;
        
        for (int i=0; i<len; i++){
            letters[s[i]-'a']++;
        }
        
        for (int i=0; i<len; i++){
            letters[t[i]-'a']--;
            if( letters[t[i]-'a'] < 0) return false;
        }
        return true;
    }
};