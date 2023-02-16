class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        
        // need post processing
        // while(left < right){
        //     mid = left + (right-left)/2;
        //     if(nums[mid]==target) 
        //         return mid;
        //     else if(nums[mid] < target)
        //         left = mid + 1;  mid+1 could be the result
        //     else
        //         right = mid;  mid could be the result
        // }
        // return nums[left]<target? left+1 : left;
        
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid]==target) 
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid-1;
        }
        // xxx 1 xxx target=0, return index(1) -> left
        // xxx 1 xxx target=2, left=mid+1 -> return left
        // learn to right bound
        return left;
    }
    
};

// x,x,x, 1, 3, x,x,x
//       l/m  r       =>l=m+1, r=m both can reduce search range
// x,x,x 1, x,x,x
//     l/m/r         => l can, but right is not change => dead loop => while(l<r)

// [1,3] target=2
// [3] target=2, 3>2 return index at 3

// [1,3] target=0
// [1] target=0, 1>0 return index at 1

// [1,3] target=4
// [3] target=4, 3<4 return index at 3, +1