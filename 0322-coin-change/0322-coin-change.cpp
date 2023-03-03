class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        
        
        int INF = n+1;
        vector<int> dp (n+1, INF);
        
        dp[0] = 0;
        for(int i=0; i<=n; i++){
            for(int &coin : coins){
                if(i >= coin)
                    dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[n]==INF? -1 : dp[n];
    }
};