class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 7ms 10.9mb
//         unordered_set<string> set (wordDict.begin(), wordDict.end());
//         int len = s.length();
//         vector<bool> dp (len+1, false);
//         dp[0] = true;
                
//         for (int i=1; i<=len; i++){
//             for(int j=i-1; j>=0; j--){
//                 //if(i-maxLen > j ) continue; // next j
                
//                 string word = s.substr(j, i-j);
//                 if(dp[j] && set.find(word)!=set.end()){
//                     dp[i] = true;
//                     break; // next i
//                 }
//             }
//         }
//         return dp[len];
        
        // 100% 0ms | 91% 7.7mb
        int len = s.size();
        vector<bool> dp(len+1,0);

        dp[0] = 1;
        for(int i=1; i<=len ;i++)
            for(string &w : wordDict){
                int wordSize = w.size();
                if(i>=wordSize && dp[i-wordSize] 
                   && s.substr(i-wordSize, wordSize)==w)
                {
                    dp[i] = 1;
                    break;
                }
            }

        return dp[len];
        
//         int len = s.size();
//         vector<bool> dp(len+1,0);

//         dp[0] = true;
//         for(int i=1; i<=len ;i++)
//             for(string &w : wordDict){
//                 if(i>= w.size() && dp[i- w.size()] 
//                    && s.substr(i- w.size(),  w.size())==w)
//                 {
//                     dp[i] = true;
//                     break;
//                 }
//             }

//         return dp[len];
        
        // ref: https://leetcode.com/problems/word-break/discuss/3179584/C%2B%2B-Easy-Solution-Using-DP
    }
};