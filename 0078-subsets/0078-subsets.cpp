class Solution {
private:
    vector<vector<int>> result;
public:
    //100% 57%
    // 
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
        
        // for(int j=i; j<nums.size(); j++){
        //     subset.push_back(nums[j]);      
        //     backtrack(nums, subset, j+1);
        //     subset.pop_back();
        // }
                    subset.push_back(nums[i]);      
            backtrack(nums, subset, i+1);
        subset.pop_back();
        backtrack(nums, subset, i+1);
    }   
};

// 