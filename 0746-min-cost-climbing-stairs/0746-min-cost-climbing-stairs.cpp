class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 14 ms, 13.6mb
//         int minCost=0, oneCost=0, twoCost=0;
//         int len = cost.size();
        
//         for(int i=2; i<=len; i++){
//             int jumpOneStep = oneCost + cost[i-1];
//             int jumpTwoStep = twoCost + cost[i-2];
//             minCost = min(jumpOneStep, jumpTwoStep);
            
//             // move one step forward
//             twoCost = oneCost;
//             oneCost = minCost;
//         }
        
//         return minCost;
        
        cost.push_back(0);
        int len = cost.size();
        for(int i=len-3; i>=0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        
        return min(cost[0], cost[1]);
    }
};

// cost index: 0..len-1
// top index: len
// if the index+step == top_index => reach top

// [1, 100, 1, 1, 1, 100]
//  0, 1,   2, 3, 4, 5     6
//                2, 3

// 3 103
// at index: 5
// minCost = 2
// oneCost = 3
// twoCost = 2


// twoCost = oneCost
// oneCost = minCost

