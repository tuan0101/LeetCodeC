class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, postfix = 1;
        int n = nums.size();
        vector<int> answer (n,1);
        
        for(int i=0; i<n; i++){
            answer[i] *= prefix;
            prefix *= nums[i];
            answer[n-i-1] *= postfix;
            postfix *= nums[n-i-1];
        }
        // i = 3    end = 0
        // prefix = 6
        // postfix = 24
        // [24, 12, 8, 6]
        return answer;
//         int prefix = 1;
//         vector<int> answer;
        
//         for(int &num : nums){
//             answer.push_back(prefix);
//             prefix *= num;
//         }
        
//         int postfix = 1;
//         for(int i=nums.size()-1; i>=0; i--){
//             answer[i] *= postfix;
//             postfix *= nums[i];
//         }

//         return answer;
    }
};

// prefix           [1, 1, 2, 6]
// postfix = 1      ........, 6
// postfix = 4      ....., 8, 6
// postfix = 12     ., 12, 8, 6]
// postfix = 24