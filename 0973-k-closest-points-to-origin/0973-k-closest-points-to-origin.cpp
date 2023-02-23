class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Greater> minHeap(points.begin(), points.end());
        
        vector<vector<int>> result;
        
        for (int i = 0; i < k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
private:    
    struct Greater{
        bool operator()(vector<int>& p, vector<int>& q){
            return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1];
        }        
    };
};

// fisrt: 2, second: 3 