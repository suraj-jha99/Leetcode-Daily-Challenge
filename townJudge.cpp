#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/* ans[i] is storing the diff bw no. of people that trusts i and 
people that i trusts.

this diff should be n-1 for the town judege [since, n-1 - 0 == n-1]

*/
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n+1,0);

        for(auto it: trust){
            ans[it[1]]++;
            ans[it[0]]--;
        }

        for(int i=1; i<=n; i++){
            if(ans[i]==n-1) return i;
        }

        return -1;
    }
};