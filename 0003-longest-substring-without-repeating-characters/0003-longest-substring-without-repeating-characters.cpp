class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // vector 90% 63%
        //vector<int> cache(256, -1);
        
        // array 93%  97%
        //int cache[128];     // there is no default value
        int cache[128]={};  // initialize all to 0
        int len = s.length();        
        int result = 0, start = 0;           
       
        for(int i=0; i<len; i++){
            if(cache[s[i]] > start){
                start = cache[s[i]];
            }
            cache[s[i]] = i+1;  
            result = max(result, i+1 - start);  
        }
        return result;
        
        // "abacbcda"
        //  01234567        -- index
        //  12345678        -- cachce
        // when i=2, start = 1, result = 2
        // when i=4, start = 2, result = 3
        // when i=5, start = 4, result = 3
        // when i=7, start = 4, result = 4

        // 50% 20%
//         unordered_map<char, int> myMap;
//         int current=0, maxString=0, start=0;
//         int len = s.length();
        
//         for(int i=0; i<len; i++){
//             if(myMap.count(s[i])>0){
//                 start = max(start, myMap[s[i]]+1); 
//                 myMap[s[i]] = i;  // insert does not override if exist
//             }
//             myMap.insert({s[i], i}); 
//             current = i-start + 1;
//             maxString = max(maxString, current);                       
//         }
        
//         return maxString;
    }
};

// "cabacd" result = 4
//  012345
// current = 4, max = 4;
// current = 
