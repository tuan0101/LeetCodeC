class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // O(NlogN)
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;      
        
        result.push_back(intervals[0]);
        for(auto interval : intervals){
            if(result.back()[1] < interval[0]){
                result.push_back(interval);
            }else{
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
            
        return result;
    }
};

// [[1,3],[2,5],[5,10],[15,18]]
// [[1,10], [15,18]]