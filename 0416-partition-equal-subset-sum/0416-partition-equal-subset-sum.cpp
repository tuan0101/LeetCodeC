class Solution {
public:      
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0), target = sum / 2;
        if(sum & 1) return false;
        bool dp[target+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = target; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[target];      
    }
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