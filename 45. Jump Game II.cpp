//45. Jump Game II


class Solution {
public:
    int help(int i,vector<int>& nums, vector<long long>& dp){
        if(i==nums.size()-1) return 0;

        if(dp[i] != -1) return dp[i];
        long long minA = INT_MAX;
        for(int j=i+1;j<=nums[i]+i && j<nums.size();j++){
            minA=min(minA,1ll+help(j,nums,dp));
        }
        return dp[i]=minA;

    }

    int jump(vector<int>& nums) {
        vector<long long>dp(nums.size(),-1);
        
        return help(0,nums,dp);
    }
};