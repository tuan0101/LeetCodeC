class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
            return false;
        
        int myArray[26] = {0}; // much faster than unordered_map
        
        for(char &c : magazine){
            myArray[c-'a']++; 
        }
        
        for(char &c : ransomNote){
            if(myArray[c-'a']==0) return false;
            myArray[c-'a']--;           
        }
        
        return true;
    }
};