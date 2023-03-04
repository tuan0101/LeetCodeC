class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--){
            dp[i] = min({costs[0] + dp[i+1],  costs[1] + dp[getTheNext8thDay(days, i)], 
                         costs[2] + dp[getTheNext31stDay(days, i)]});
            //dp[i] = min(dp[i], costs[2] + dp[getTheNext31stDay(days, i)] );
            //min({a, b, c}); new syntax
        }
        
        return dp[0];
    }
    
    int getTheNext8thDay(vector<int>& days, int start){
        int nextDay = days[start] + 7;
        while(start<days.size() && days[start] < nextDay){
            start++;
        }
        return start;
    }
    
    int getTheNext31stDay(vector<int>& days, int start){
        int nextDay = days[start] + 30;
        while(start<days.size() && days[start] < nextDay){
            start++;
        }
        return start;
    }
};

// 1 4 6 7 8 20
// 7...... 2 2
// 1 7