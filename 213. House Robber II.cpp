//213. House Robber II




class Solution {
public:

//this is same logic question an house robber diffrence is first we have to find out the the ans excuding the first  and find out the another ans excluding the the last and taking the maximum of both the ans 

    int f(int i,vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 0;

        if(dp[i] != -1) return dp[i];
        int take=f(i+2,nums,dp)+nums[i];
        int untake=f(i+1,nums,dp);

        dp[i]= max(take,untake); 
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        vector<int> excfirst,exclast;
        int ans1,ans2;
        for(int i=0;i<nums.size();i++){
            if(i == 0) exclast.push_back(nums[i]);
            else if(i == nums.size()-1) excfirst.push_back(nums[i]);
            else{
                excfirst.push_back(nums[i]);
                exclast.push_back(nums[i]);
            }
        }
        ans1=f(0,excfirst,dp1);
        ans2=f(0,exclast,dp2);
        return max(ans1,ans2);
    }
};