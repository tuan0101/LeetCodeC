class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l=0, sum=0, len=n + 1;

        for(int r=0; r<n; r++){
            sum += nums[r];
            while(sum >= target){
                len = min(len, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        //return len==nums.size()+1? 0 : len;
        // same as
        return len % (n + 1);
    }
};


// [2,3,1,2,4,3] target = 7 | cur_sum = 3 | len = 2
//            l
//            r