class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(N^2 + O(NlogN)) = O(N^2)
        sort(nums.begin(), nums.end()); // O(NlogN)
        
        int len = nums.size();
        int l, r;
        vector<vector<int>> result;
        
        for(int i=0; i<len-2; i++){ //O(N^2)
            if(i>0 && nums[i] == nums[i-1]) continue;
            l = i+1;
            r = len-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == 0){
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    
                    while(l+1<r && nums[l] == nums[l+1]) l++; // l and r has to be different
                    while(r-1>l && nums[r] == nums[r-1]) r--;
                    // in the while loop, l or r stops at the last repeated number
                    // => increment 1 more to move on the next number
                    l++; r--;
                }
                else if(sum < 0) 
                    l++;
                else 
                    r--;               
            }
        }
        return result;
    }
};
// because there are high chance to get duplicate triplets, we need to sort first
// [-1, 0, 1, 2, -1, 4]
// [-1, -1, 0, 1, 2, 4]

// first = nums[1]
// second
// third