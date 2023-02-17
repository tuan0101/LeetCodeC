class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        vector<int> result(2, -1);
        if(nums.size()==0) return result;
        
        // left most
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if(nums[left] != target) return result;
        result[0] = left;
        
        //right most
        right = nums.size()-1;
        while(left<right){
            mid = left + (right-left)/2+1;
            if(nums[mid] <= target)
                left = mid;
            else
                right = mid-1;
        }
        result[1] = right;
        return result;
    }
};


// xxxx 8888 xxxx
// left most...right most

// always check 2 elements for the dead loop
// notate left right and mid, and check if left and right will be moved for every case

// for example:

// 8 8
// l r/m
// nums[mid] == target , left must move,
// nums[mid] < target , left must move,
// nums[mid] > target , right must move,
// => if(nums[mid] <= target).. is the right condition