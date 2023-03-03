class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        // 97% 98% with array
        // same result with sort
        sort(begin(coins), end(coins));
        int INF = n+1;
        int dp[n+1];
        
        dp[0] = 0;
        for(int i=1; i<=n; i++){ 
            
            dp[i] = INF;            
            for(int &coin : coins){
                if(i >= coin)
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                else 
                    break;
            }
        }
        return dp[n]==INF? -1 : dp[n];
        
        // 76% 62%
        // 77% 70% with sort - kind of same
//         sort(coins.begin(), coins.end());
//         int INF = n+1;
//         vector<int> dp (n+1, INF);
        
//         dp[0] = 0;
//         for(int i=0; i<=n; i++){
//             for(int &coin : coins){
//                 if(i >= coin)
//                     dp[i] = min(dp[i], 1+dp[i-coin]);
//                 else
//                     break;
//             }
//         }
//         return dp[n]==INF? -1 : dp[n];
    }
};