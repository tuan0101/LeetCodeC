class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int p : prices){
            if(minPrice > p)
                minPrice = p;
            int currentProfit = p-minPrice;
            if(currentProfit > maxProfit){
                maxProfit = currentProfit;
            }
            
        }
        return maxProfit;
    }
};

// 7, 1, 5, 3, 6, 4
// just record min price and max profit

