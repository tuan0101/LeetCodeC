class Solution {
public:      
    int8_t dp[10001] = {[0 ... 10000] = -1};
    bool canPartition(vector<int>& nums) {
    //     int totalSum = accumulate(begin(nums), end(nums), 0);
    //     cout<<"sum: "<<totalSum;
    //     if(totalSum & 1) return false;
    //     return subsetSum(nums, totalSum / 2);
    // }
    // bool subsetSum(vector<int>& nums, int sum, int i = 0) {
    //     if(sum == 0) return true;
    //     if(i >= size(nums) || sum < 0) return false; 
    //     if(dp[sum] != -1) return dp[sum];
    //     return dp[sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
    // }
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};