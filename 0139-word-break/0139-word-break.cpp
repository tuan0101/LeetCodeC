class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
        
                vector<bool> ans(s.size()+1,0);
        ans[0]=1;
        for(int i=1;i<ans.size();i++)
            for(string &w:wordDict)
                if(i>=w.size() && ans[i-w.size()] && s.substr(i-w.size(),w.size())==w)
                {
                    ans[i]=1;
                    break;
                }
        return ans.back();
    }
};