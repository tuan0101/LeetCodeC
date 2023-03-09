class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> result;
        // vector<int> comb;
        // bool used[nums.size()]; 
        // memset(used, false, sizeof nums);
        // getPermutation(result, comb, nums, used);
        // return result;
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
    
//     void getPermutation(vector<vector<int>>& result, vector<int>& comb, vector<int>& nums, bool used[]){
//         if(comb.size()==nums.size()){
//             result.push_back(comb);
//             return;
//         }
        
//         for(int i=0; i<nums.size(); i++){
//             if(used[i]) continue;
//             comb.push_back(nums[i]);
//             used[i] = true;
//             getPermutation(result, comb, nums, used);
//             used[i] = false;
//             comb.pop_back();
//         }       
//         delete[] used;
//     }
    
        // swap 100% 20%
        void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                permute(nums, i + 1, perms);
            }
        }
    }
};
           
// comb: [1, 3]