class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> answer;
        
        for(int &num : nums){
            answer.push_back(prefix);
            prefix *= num;
        }
        
        int postfix = 1;
        for(int i=nums.size()-1; i>=0; i--){
            answer[i] *= postfix;
            postfix *= nums[i];
        }

        return answer;
    }
};

// prefix           [1, 1, 2, 6]
// postfix = 1      ........, 6
// postfix = 4      ....., 8, 6
// postfix = 12     ., 12, 8, 6]
// postfix = 24