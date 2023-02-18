class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], tracker = 0;
        
        for(int &n : nums){
            if(tracker==0)
                candidate = n;
            tracker += (candidate==n)? 1 : -1;
        }
        
        return candidate;
    }
};

// treat every other element as an x
// pattern: xMMxxxMMxMxMMMM
// assuming the current is the ML, and vote for it

// tracker = 1, candidate = M