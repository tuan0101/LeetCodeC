class Solution {
private:
    vector<vector<int>> result;
    vector<int> comb;
public:
    
    // 62% 40%
    // O(2^N)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //O(NlogN)
        sum(candidates, target, 0);
        return result;
    }
    
    void sum(vector<int>& candidates, int target, int i){
        if(target == 0){
            result.push_back(comb);
            return;
        }
        
        if(i>= candidates.size() || candidates[i] > target)
            return;
        
        comb.push_back(candidates[i]);
        sum(candidates, target - candidates[i], i+1);
        comb.pop_back();
        // ignore all repeated current number
        while(i<candidates.size()-1 && candidates[i+1]==candidates[i]){
            i++;
        }        
        sum(candidates, target, i+1);
        
        // 50% 87%
//         int prev = -1;
//         for(int i=begin; i<candidates.size(); i++){
//             if(candidates[i]==prev) continue;
            
//             comb.push_back(candidates[i]);
//             sum(candidates, target - candidates[i], i+1);
//             comb.pop_back();
//             prev = candidates[i];
//         }
            
    }
};

// 2    2   2   5    target=9
// i  next_i

// 5
// [2 2 5]