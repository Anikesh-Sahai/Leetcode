//122. Best Time to Buy and Sell Stock II




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        dp[0]=prices[0];
        for(int i=1;i<n;i++){
            dp[i]=min(prices[i],prices[i-1]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            dp[i]=prices[i]-dp[i];
            result=result+dp[i];
        }
        return result;
    }
};