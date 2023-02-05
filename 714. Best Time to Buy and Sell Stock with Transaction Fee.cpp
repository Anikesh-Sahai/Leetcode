//714. Best Time to Buy and Sell Stock with Transaction Fee


class Solution {
public:
    int help(int i, int map, int n, int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(i==n) return 0;

        if(dp[i][map] != -1) return dp[i][map];

        if(map){        //buy case
            dp[i][map]=max(-prices[i]+help(i+1,0,n,fee,prices,dp),0+help(i+1,1,n,fee,prices,dp));
        }
        else{           // sell case
            dp[i][map]=max(prices[i]-fee+help(i+1,1,n,fee,prices,dp),0+help(i+1,0,n,fee,prices,dp));
        }
        return dp[i][map];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return help(0,1,n,fee,prices,dp);        
    }
};