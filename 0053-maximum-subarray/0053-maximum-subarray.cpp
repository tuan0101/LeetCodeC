class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // or INT_MIN;
        int curSum = 0;
        for(int &n : nums){
            if(curSum <= 0){
                curSum = n;  // treat subarray as a single number
                             // ignore any negative number
            }else{
                curSum += n;                
            }    
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};