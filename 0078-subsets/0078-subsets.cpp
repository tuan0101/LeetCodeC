class Solution {
private:
    vector<vector<int>> result;
public:
    //time: N*2^N
    // every subset could have N length
    // 2^N is the number of subsets
    vector<vector<int>> subsets(vector<int>& nums) {        
        vector<int> subset;
        backtrack(nums, subset, 0);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& subset, int i){
        if(i>=nums.size()){
            result.push_back(subset);
            return;
        }
        //result.push_back(subset);
        
        // 100 57%
        // for(int j=i; j<nums.size(); j++){
        //     subset.push_back(nums[j]);      
        //     backtrack(nums, subset, j+1);
        //     subset.pop_back();
        // }
        
        // 100 57%
        subset.push_back(nums[i]);      
        backtrack(nums, subset, i+1);
        subset.pop_back();
        backtrack(nums, subset, i+1);
    }   
};

// 