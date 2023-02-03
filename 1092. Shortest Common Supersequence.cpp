//1092. Shortest Common Supersequence 

class Solution {
public:
//Lcs tabulation
    int helptab(string text1, string text2,vector<vector<int>>& dp){
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }

    //LCS tabulation se dp ko update kr liya

    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        int LCSLen= helptab(str1,str2,dp);
        string SCS="";
        int i=0,j=0;

        // yaha pr hamne shortest commom sequence nikalna chlu kiya 
        while(i<str1.size() && j<str2.size()){
            if(str1[i]==str2[j]){
                SCS=SCS+str1[i];
                i++;
                j++;
            }
            else{
                if(dp[i+1][j]>dp[i][j+1]){
                    SCS=SCS+str1[i];
                    i++;
                } 
                else {
                    SCS=SCS+str2[j];
                    j++;
                }
            }
        }
        //yaha pr dono m se ek khali ho chuka hoga or ek bach jayega islea neche ki dono condition bache hue ko full fill karne k lea 
        while(i<str1.size()){
            SCS=SCS+str1[i];
            i++;
        }
        while(j<str2.size()){
            SCS=SCS+str2[j];
            j++;
        }

        return SCS;
    }
};