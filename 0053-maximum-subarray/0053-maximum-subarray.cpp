class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // or nums[0];
        int curSum = 0;
        for(int &n : nums){
            if(curSum <= 0)
                curSum = n;  // treat subarray as a single number
                             // ignore any negative number
            else
                curSum += n;                
            
            // equivalent
            // curSum = (curSum+n, n);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;        
    }
};

// curMax = 4
// maxSum = 4