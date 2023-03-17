class Solution {
public:      
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        // 95% 90%
        int sum = accumulate(begin(nums), end(nums), 0), target = sum / 2;
        if(sum & 1) return false;
        bool dp[target+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        
        // current = 3
        // if sum(5) is achievable then sum(5-3) must be achievable
        // to check if we can make sum of 5, then we check if we can make sum of 2
        for(int num : nums) 
            for(int j = target; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
        return dp[target];    
    }
    
    
            
        // 92% 20% back tracking + 2d DP        
        // 80% 80% 2d DP
//         int sum = 0;
//         int n = nums.size();
//         for(int i=0;i<n;++i)
//             sum += nums[i];
        
//         if(sum & 1)     //ODD sum
//             return false;
        
//         bool dp[n+1][sum/2+1];
//         //Fill DP table (Subset Sum Problem code)
//         for(int i=0;i<=n;++i)
//         for(int j=0;j<=sum/2;++j)
//         {
//             if(i==0 || j==0)    //Base Case
//                 dp[i][j] = false;
//             else if(nums[i-1] > j)    //SkIP case
//                 dp[i][j] = dp[i-1][j];
//             else if(nums[i-1]==j)
//                 dp[i][j] = true;
//             else
//                 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
//         }
//         return dp[n][sum/2];

//    }
    
};
// [2,2,3,5]
// dp[2-2] dp[2] = true
// dp[4-2] dp[4] = true // duplicate of 2, beefore reach the 2nd 2
// dp[5-3] dp[5] = true
// dp[3-3] dp[3] = true
// dp[6-3] dp[6] = true // duplicate of 3 => should be iterate through right->left

//[1,5,11,5]
// right => left
// dp[1-1] = true => dp[1] = true

// dp[6-5] = true; => dp[6] = true
// dp[5-5] = true; => dp[5] = true

// dp[11-11]=true => dp[11] = true
// d[[11-5] = true => dp[11] = true