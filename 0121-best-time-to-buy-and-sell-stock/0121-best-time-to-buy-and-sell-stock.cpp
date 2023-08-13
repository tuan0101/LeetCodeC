class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0], maxProfit = 0;
        for(int p : prices){
            if(p < minPrice)
                minPrice = p;
            int currentProfit =  p - minPrice;  
            if(currentProfit > maxProfit)
            {
                maxProfit = currentProfit;
            }
        }
        return maxProfit;
    }
};

// 7, 1, 5, 3, 6, 4
// just record min price and max profit