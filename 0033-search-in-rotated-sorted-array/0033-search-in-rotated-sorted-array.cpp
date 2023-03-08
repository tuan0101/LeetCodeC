class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 50%, 50%
//         int n = nums.size();
//         int first = nums[0];
        
//         int m,l = 0, r = n-1;
        
//         while(l<=r){
//             m = l + (r-l)/2;
//             if(nums[m] == target) return m;
            
//             //if target and mid are both in the same side
//             if((nums[m] < first) == (target < first)){
//                 if(nums[m] < target)
//                     l = m + 1;
//                 else if(nums[m] > target)
//                     r = m - 1;
//                 else 
//                     return m;
//             }else{
//                 // mid is in the shifted area
//                 if(target < first)
//                     l = m + 1;
//                 // target is in the shifted area
//                 // => mid is on the right side
//                 else
//                     r = m - 1;
//             }

//         }
//         return -1;
            int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        
        double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;
                   
        if (num < target)
            lo = mid + 1;
        else if (num > target)
            hi = mid;
        else
            return mid;
    }
    return -1;
    }
};
