class Solution {
private:
    vector<int> combination;
    vector<vector<int>> result;
public:
    // we make 2 decision each time => O(2^)
    // if 1 is the smallest candidate, it takes target times to reach target
    // => O(2^T)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        validateSum(candidates, target, 0);
        return result;
    }
    
    void validateSum(vector<int>& candidates, int target, int i){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        // check i is valid before sum
        if(i >= candidates.size() || target < 0)
            return;
               
        // 80%, 60%
        
        combination.push_back(candidates[i]);
        validateSum(candidates, target-candidates[i], i);   
        combination.pop_back();
        validateSum(candidates, target , i + 1);
        
        // 80% 60$
        // starting from i
        // for(int j=i; j<candidates.size(); j++){
        //     combination.push_back(candidates[j]);
        //     validateSum(candidates, target-candidates[j], j);   
        //     combination.pop_back();
        // }
    }
};
