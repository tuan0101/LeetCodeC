class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 100% 45%
        // O(N!*N) the decision tree has N! leaf, and each leaf have N calls
        vector<vector<int>> result;
        vector<int> comb;
        const int n = nums.size();
        vector<bool> used(nums.size(), false);
        getPermutation(result, comb, nums, used);
        return result;
        // vector<vector<int>> perms;
        // permute(nums, 0, perms);
        // return perms;
    }
    
    void getPermutation(vector<vector<int>>& result, vector<int>& comb, vector<int>& nums, vector<bool>& used){
        if(comb.size()==nums.size()){
            result.push_back(comb);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            // make choice
            comb.push_back(nums[i]);
            used[i] = true;
            // this line finishes when it cannot make choice anymore
            // or reach goal
            getPermutation(result, comb, nums, used);
            // undo the choice
            used[i] = false;
            comb.pop_back();
        }       
    }
    
        // swap 10-100% 20%
        // void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
        // if (i == nums.size()) {
        //     perms.push_back(nums);
        // } else {
        //     for (int j = i; j < nums.size(); j++) {
        //         swap(nums[i], nums[j]);
        //         permute(nums, i + 1, perms);
        //     }
        // }
    //}
};
           