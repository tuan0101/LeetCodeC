class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();

        // key: complement of the current number
        // value: the index of the number that made this complement
        unordered_map<int, int> myMap;
        
        for(int i=0; i<len; ++i){
            int complement = target - nums[i];
            if(myMap.count(nums[i]))
                return {myMap[nums[i]], i};
            else
                myMap[complement] = i;
        }
        return {};
    }
};

// current number: 4
// complement: 3 => myMap{[3, 0]}
// complement: 4 => myMap{[3, 0], [4,1]}
// complement: 2