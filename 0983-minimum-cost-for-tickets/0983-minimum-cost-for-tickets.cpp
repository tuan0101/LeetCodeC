class Solution {
public:

    int mincostTickets(vector<int>& DAYS, vector<int>& cost) {
        //
        unordered_set<int> days(DAYS.begin(),DAYS.end());
        vector<int> dp(367);
        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i) != days.end())
            {
			// cost of ith day , decision of ith day will be
                dp[i] = min({ dp[i - 1] + cost[0],   // 1st case
                             dp[max(0, i - 7)] + cost[1],  // 2nd case
                             dp[max(0, i - 30)] + cost[2]});  // 3rd case
            }
        }
        return dp[365];
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

// 1 4 6 7 8 20
// 7...... 2 2
// 1 7