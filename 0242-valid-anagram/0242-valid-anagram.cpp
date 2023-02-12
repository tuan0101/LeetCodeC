class Solution {
public:
    bool isAnagram(string s, string t) {
        // 6ms 7.2mb
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        
        return true;
        
        // 4ms 7.4mb
//         int letters[26] = {0};
//         int len = s.length();
        
//         if(len != t.length()) return false;
        
//         for (int i=0; i<len; i++){
//             letters[s[i]-'a']++;
//         }
        
//         for (int i=0; i<len; i++){
//             letters[t[i]-'a']--;
//             if( letters[t[i]-'a'] < 0) return false;
//         }
//         return true;
    }
};