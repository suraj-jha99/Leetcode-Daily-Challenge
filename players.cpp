#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int idx,int prev,vector<pair<int,int>> &nums,int n,vector<vector<int>> &dp){
        if(idx >= n) return 0;

        if(dp[prev+1][idx] != -1){
            return dp[prev+1][idx];
        }
    
        //case1 : we are able to take cur player
        if(prev == -1 || nums[idx].second >= nums[prev].second){
            return dp[prev+1][idx] = max( nums[idx].second + f(idx+1,idx,nums,n,dp),
                       0 + f(idx+1,prev,nums,n,dp));
        }

        //case2 : we are not able to take cur player
        return dp[prev+1][idx] = 0 + f(idx+1,prev,nums,n,dp);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();

        vector<pair<int,int>> nums;
        for(int i=0; i<n; i++){
            nums.push_back({ages[i],scores[i]});
        }

        sort(nums.begin(),nums.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return f(0,-1,nums,n,dp);
    }
};