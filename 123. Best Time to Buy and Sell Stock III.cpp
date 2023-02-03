//123. Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> Fdp(n);
        vector<int> Rdp(n);

        Rdp[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            Rdp[i]=max(prices[i],Rdp[i+1]);
        }
        //finding profit at ith day;
        for(int i=0;i<n;i++){
            Rdp[i]=Rdp[i]-prices[i];
        }
        //finding max profit any tine i dosen't matter
        for(int i=n-2;i>=0;i--){
            Rdp[i]=max(Rdp[i],Rdp[i+1]);
        }

        Fdp[0]=prices[0];
        for(int i=1;i<n;i++){
            Fdp[i]=min(prices[i],Fdp[i-1]);
        }
        //finding profit att ith day
        for(int i=0;i<n;i++){
            Fdp[i]=prices[i]-Fdp[i];
        }
        //finding max profit i not matter
        for(int i=1;i<n;i++){
            Fdp[i]=max(Fdp[i],Fdp[i-1]);
        }

        //ADD both max profit
        for(int i=0;i<n;i++){
            Fdp[i]=Fdp[i]+Rdp[i];
        }
        return *max_element (Fdp.begin(), Fdp.end());
    }
};