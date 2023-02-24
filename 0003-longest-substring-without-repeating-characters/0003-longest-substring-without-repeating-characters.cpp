class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> myMap;
        int current=0, maxString=0, start=0;
        int len = s.length();
        
        for(int i=0; i<len; i++){
            if(myMap.count(s[i])>0){
                start = max(start, myMap[s[i]]+1); 
                myMap[s[i]] = i;  // insert does not override if exist
            }
            myMap.insert({s[i], i}); 
            current = i-start + 1;
            maxString = max(maxString, current);                       
        }
        
        return maxString;
    }
};

// "cabacd" result = 4
//  012345
// current = 4, max = 4;
// current = 
