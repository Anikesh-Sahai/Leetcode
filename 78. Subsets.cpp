// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).

//The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    
    void support(int i, vector<int> &set, vector<vector<int>> &res, vector<int> &nums){
        if(i==nums.size()){
            res.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        support(i+1,set,res,nums);
        set.pop_back();
        support(i+1,set,res,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
/*      itterative method(wrong) MLE
        vector<vector<int>> set;   
        vector<int> empty;          // creating empty set
        set.push_back(empty);       // pushing [] set vector
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<set.size();j++){      // checking for array in set 
                vector<int> curr=set[j];        // copying in curr vector 
                curr.push_back(nums[i]);        // inserting nums[i] in curr
                set.push_back(curr);            // adding curr in set
            }
        }
       return set;
*/
        
        // recursive approach backtracking
        vector<vector<int>> result;
        vector<int> empty;
        support(0,empty,result,nums);
        return result;
        
    }
};