#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//app 1: prefix sum approach
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp; //(rem,freq)
        mp[0]=1;
        
        int prefsum=0,ans=0;
        for(int i=0; i<n; i++){
               prefsum += nums[i];

               int rem = prefsum % k;
               if(rem < 0) rem += k;
//if, that rem already exists, then there is a subaray whose sum is div by k
               if(mp.find(rem) != mp.end()) ans += mp[rem];

               //update map
               mp[rem]++;
        }

        return ans;
    }
};