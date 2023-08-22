class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int len=0, res=0, l=0;
        long sum = 0; // use long to avoid overflow

        for(int r=0; r<nums.size(); r++){
            len++;
            sum += nums[r];

            if((long)nums[r]*len  <= sum + k){
                res = max(res, len);              
            }else{
                sum -= nums[l];
                l++;
                len--;                
            }
        }
        return res;
    }
};



// 1,4,8,13        len=3;    res=2; sum=5; ()r*len < sum + k) 8*3 < 13 + 5
//     l
//        r