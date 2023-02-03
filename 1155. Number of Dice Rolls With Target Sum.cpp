//1155. Number of Dice Rolls With Target Sum

class Solution {
public:

    int help(int n, int k, int target,vector<vector<int>>& dp){
        // base conditions
        if(target<0) return 0;
        if(n!=0 && target==0) return 0;  //dice abhi bache h or target aagaya
        if(n==0 && target!=0) return 0;  //dice khatam pr target nahi aaya
        if(n==0 && target==0) return 1;  //dice bhi khatam or target bhi

        if(dp[n][target] != -1) return dp[n][target];
        int ans=0;
        int modulo=(1e9)+7;
        for(int i=1;i<=k;i++){
            ans=ans+help(n-1,k,target-i,dp);
            ans = ans % modulo;
        }
        return dp[n][target]=ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return help(n,k,target,dp);
    }
};