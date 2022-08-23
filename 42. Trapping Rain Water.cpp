// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

class Solution {
public:
    vector<int> maxLeft(vector<int>H, int n){
        vector<int> maxL;
        int max=H[0];
        maxL.push_back(max);
        for(int i=1;i<n;i++){
            if(max<=H[i]) max=H[i];
            maxL.push_back(max);    
        }
        //for(int i=0;i<n;i++){cout<<maxL[i]<<endl;}
        return maxL;
    }
    vector<int> maxRight(vector<int>H, int n){
        vector<int> maxR;
        int max=H[n-1];
        maxR.push_back(max);
        for(int i=n-2;i>=0;i--){
            if(max<=H[i]) max=H[i];
            maxR.push_back(max);    
        }
        //for(int i=0;i<n;i++){cout<<maxR[i]<<endl;}
        reverse(maxR.begin(),maxR.end());
        return maxR;    
    }    
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxL=maxLeft(height,n);
        vector<int> maxR=maxRight(height,n);
        int RainWater=0;
        for(int i=0;i<n;i++){
            int Rain=min(maxL[i],maxR[i])-height[i];
            RainWater=RainWater+Rain;
        }
        return RainWater;
    }
};