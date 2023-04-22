class Solution {
public:
    int maxArea(vector<int>& height) {
        // 50% 50%
        // O(N)
        int water = 0;
        int left = 0, right = height.size()-1;
        
        while(left < right){
            int curHeight = min(height[left], height[right]);
            int curWater = (right-left) * curHeight;
            water = max(water, curWater);
            
            while(left < right && height[left] <= curHeight)
                left++;
            while(left < right && height[right] <= curHeight)
                right--;
        }
        return water;
    }
};

// height * width