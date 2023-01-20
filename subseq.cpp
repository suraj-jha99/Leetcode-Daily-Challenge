#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//app 1: brute force using recursion in O(2^N*N)
    
    set<vector<int>> st;

    void f(int idx,int n,int prev,vector<int> nums,vector<vector<int>> &res,
    vector<int> &ans){

         //base case
         if(idx == n){
             //size is atleast 2 and it is unique 
             if(ans.size() >= 2 && st.find(ans) == st.end()){
                   res.push_back(ans);
             }

             //update set
             st.insert(ans);
             return;
         }

         //take 
         if(prev == -200 || nums[idx] >= prev){
             ans.push_back(nums[idx]);
             f(idx+1,n,nums[idx],nums,res,ans);
             //backtrack
             ans.pop_back();
         }
        
         //not take 
         f(idx+1,n,prev,nums,res,ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> ans;

        f(0,n,-200,nums,res,ans);//-200 is just an out of bound number to denote empty
        return res;
    }
};