class Solution {
public:
    int solve(int ind, int n, vector<int>& days, vector<int>& costs, vector<int> &dp) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int oneDay = costs[0] + solve(ind + 1, n, days, costs, dp);

        int i;
        for(i = ind; i < n and days[i] < days[ind] + 7; i++);
        int week = costs[1] + solve(i, n, days, costs, dp);

        for(i = ind; i < n and days[i] < days[ind] + 30; i++);
        int month = costs[2] + solve(i, n, days, costs, dp);

        return dp[ind] = min({oneDay, week, month});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solve(0, n, days, costs, dp);
        // 72% 57%
//         int n = days.size();
//         vector<int> dp(n+1);
//         dp[n] = 0;
        
//         for(int i = n-1; i>=0; i--){
//             int theNext8thDay = i;
//             int theNext31stDay = i;
//             while(theNext8thDay<n && days[theNext8thDay] < days[i]+7) theNext8thDay++;
//             while(theNext31stDay<n && days[theNext31stDay] < days[i]+30) theNext31stDay++;
            
//             dp[i] = min({costs[0] + dp[i+1],  costs[1] + dp[theNext8thDay], 
//                          costs[2] + dp[theNext31stDay]});
//         }        
//         return dp[0];
    }
};
