class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // quick select
        int l = 0, r = points.size() - 1;
        k--;
        while(true) {
            int p = Partition(points, l, r);
            if (p == k)
                break;
            if (p < k) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }
    
    int Partition(vector<vector<int>>& A, int left, int right){
        int pivot = Distance(A[right]);
        for(int i=left; i<right; i++){
            if(Distance(A[i]) < pivot)
                swap(A[i], A[left++]);
        }
        swap(A[right], A[left]);
        return left;
    }
    
    bool LessThan(vector<int>& p, vector<int>& q){
        return p[0]*p[0]+p[1]*p[1] < q[0]*q[0]+q[1]*q[1];
    }
    
    int Distance(vector<int>& point){
        return point[0]*point[0]+point[1]*point[1];
    }
        // min heap 50% 50%
//         priority_queue<vector<int>, vector<vector<int>>, Greater> minHeap(points.begin(), points.end());
        
//         vector<vector<int>> result;
        
//         for (int i = 0; i < k; i++){
//             result.push_back(minHeap.top());
//             minHeap.pop();
//         }
//         return result;
//    } // use this, remove top
// private:    
//     struct Greater{
//         bool operator()(vector<int>& p, vector<int>& q){
//             return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1];
//         }        
//     };
};

// fisrt: 2, second: 3 