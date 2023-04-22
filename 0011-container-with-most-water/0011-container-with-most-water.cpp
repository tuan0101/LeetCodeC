class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int left = 0, right = height.size()-1;
        
        while(left < right){
            int curHeight = min(height[left], height[right]);
            int curWater = (right-left) * curHeight;
            water = max(water, curWater);
            
            if(height[left]<height[right])
                left++;
            else right--;
        }
        return water;
    }
};

// height * width