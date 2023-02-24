class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // vector 90% 63%
//         vector<int> cache(256, -1);
//         int len = s.length();        
//         int result = 0, start = -1;               
       
//         for(int i=0; i<len; i++){
//             if(cache[s[i]] > start){
//                 start = cache[s[i]];
//             }
//             cache[s[i]] = i;
//             result = max(result, i-start);
//         }
//         return result;
        
        int store[128]={0}; //array to store the occurences of all the characters
        int l=0;    
        int r=0;   
        int ans=0;  
        
        while(r<s.length())    
        {
            store[s[r]]++;               
            while(store[s[r]]>1) {
                store[s[l]]--;   
                l++;         
            }            
            ans = max(ans,r-l+1);   
            r++;        
        }
        return ans;


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
