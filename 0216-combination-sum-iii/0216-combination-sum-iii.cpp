class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // 100% 50%
        vector<vector<int>> result;
        vector<int> comb;
        sum(result, comb, k, n, 1);
        return result;
    }
    
    void sum(vector<vector<int>> &result, vector<int> &comb, int k, int target, int candidate){
        if(target == 0 && k==0){
            result.push_back(comb);
            return;
        }
        
        if(candidate>9 || k<=0 || candidate > target)
            return;
        
        // include candidate in combination
        comb.push_back(candidate);
        sum(result, comb, k-1, target-candidate, candidate+1);

        // not include candidate in combination
        comb.pop_back();
        sum(result, comb, k, target, candidate+1);
    }
};
