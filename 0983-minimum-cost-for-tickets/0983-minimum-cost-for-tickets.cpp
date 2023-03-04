class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // 72% 57%
         int n = days.size();
         vector<int> dp(n+1);
         dp[n] = 0;
        
         for(int i = n-1; i>=0; i--){
             int theNext8thDay = i;
             int theNext31stDay = i;
            // find the index on the 8th day 
            // start couting from the day purchase week ticket
             while(theNext8thDay<n && days[theNext8thDay] < days[i]+7) theNext8thDay++;
            // find the index on the 31st day 
            // start counting from the day purchase month ticket
             while(theNext31stDay<n && days[theNext31stDay] < days[i]+30) theNext31stDay++;
            
             dp[i] = min({costs[0] + dp[i+1],  costs[1] + dp[theNext8thDay], 
                          costs[2] + dp[theNext31stDay]});
         }        
         return dp[0];
    }
};
