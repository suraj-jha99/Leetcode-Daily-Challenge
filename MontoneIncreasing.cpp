#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/* two cases possible
1. maxsub sum is in non-circular array ->kadanes algo
2. maxsub sum is in circular array -> (totalsum - minsum of non-cir array)

return max of above two cases.
*/
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        int maxsum=INT_MIN,minsum=INT_MAX;
        int totalsum=0;
        int cursum1=0;//rep. cur max sum
        int cursum2=0;//rep. cur min sum

        for(int x: nums){
             totalsum += x;

             //max sum caln
             cursum1 += x;
             maxsum = max(maxsum,cursum1);
             if(cursum1 < 0) cursum1=0;

             //min sum caln
             cursum2 += x;
             minsum = min(minsum,cursum2);
             if(cursum2 > 0) cursum2=0;
        }

        //if all no.s are -ve
        if(totalsum - minsum == 0) return maxsum;

        return max(maxsum,totalsum - minsum);
    }
};


 