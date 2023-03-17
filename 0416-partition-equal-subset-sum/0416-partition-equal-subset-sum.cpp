class Solution {
public:      
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        // int sum = accumulate(begin(nums), end(nums), 0), target = sum / 2;
        // if(sum & 1) return false;
//         bool dp[target+1]; memset(dp, false, sizeof dp);
//         dp[0] = true;                              // 0 sum is always achievable
//         for(int num : nums) 
//             for(int j = target; j >= num; j--)    // essential to start right to left
//                 if(dp[j - num])                    // if j - num was previously achievable
//                     dp[j] = true;                  // we can add num to it and make j achievable as well
            
//         return dp[target];      
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum & 1) return false;
        int sum = totalSum/2;
        dp.clear();
        dp.resize(nums.size()+1, vector<int>(sum +1, -1));
        return subsetSum(nums, sum);
    }
    bool subsetSum(vector<int>& nums, int sum, int i = 0) {
        if(sum == 0) return true;
        if(i >= size(nums) || sum < 0) return false; 
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
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