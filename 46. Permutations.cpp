//  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


class Solution {
public:
    
    void result(vector<int> &store, vector<int> &nums, vector<vector<int>> &ans, int map[])
    {
        if(store.size()==nums.size()){
            ans.push_back(store);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!map[i]){
                store.push_back(nums[i]);
                map[i]=1;
                result(store,nums,ans,map);
                store.pop_back();
                map[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        int map[nums.size()];
        for(int i=0;i<nums.size();i++) map[i]=0;
        result(store,nums,ans,map);
        return ans;
    }
};


//time complexity= n!*n
//space complexity= O(n)*O(n)   
// one O(n) for structur we are using and another for map marking
// for more optimal approach look in your notebook where space complexity is reduse to its minimal point