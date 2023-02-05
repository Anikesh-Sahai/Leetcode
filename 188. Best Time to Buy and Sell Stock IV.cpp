//188. Best Time to Buy and Sell Stock IV


class Solution {
public:
    int help(int i,int map,int k,int n,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(k==0) return 0;
        if(i==n) return 0;


        if(dp[i][map][k] != -1) return dp[i][map][k];
        if(map){        //buy case
            dp[i][map][k]=max(-prices[i]+help(i+1,0,k,n,prices,dp),0+help(i+1,1,k,n,prices,dp));
        }
        else{           // sell case
            dp[i][map][k]=max(prices[i]+help(i+1,1,k-1,n,prices,dp),0+help(i+1,0,k,n,prices,dp));
        }
        return dp[i][map][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return help(0,1,k,n,prices,dp);        
    }
};