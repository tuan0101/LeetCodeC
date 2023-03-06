class Solution {
public:
    int uniquePaths(int m, int n) {       
        // 100% 90%
        int dp[m][n];
        // memset only works 0 and -1 bc it works BYTE by BYTE
        memset(dp, 0, sizeof dp); // fill 1 here does not work
        dp[0][0] = 1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // top + left
                if(j>0)
                    dp[i][j] = dp[i][j-1]; // left
                if(i>0)
                    dp[i][j] += dp[i-1][j]; // top
            }
        }
        return dp[m-1][n-1];
    }
};