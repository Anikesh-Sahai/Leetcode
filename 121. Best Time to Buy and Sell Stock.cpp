//121. Best Time to Buy and Sell Stock




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int result=0;
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-mini;
            if(mini>prices[i]) mini=prices[i];
            result=max(result,profit);
        }
        return result;
    }
};