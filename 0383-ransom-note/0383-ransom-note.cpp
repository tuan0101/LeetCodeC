class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length())
            return false;
        
        unordered_map<char, int> myMap;
        
        for(char &c : magazine){
            myMap[c]++; 
        }
        
        for(char &c : ransomNote){
            if(myMap[c]==0) return false;
            myMap[c]--;           
        }
        
        return true;
    }
};