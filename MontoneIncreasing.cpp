 #include<bits/stdc++.h>
 using namespace std;
 
 class Solution {
public:
/* own approach ::
we have three choices ==> all 0's,all 1's or (0's and 1's)
out of these choices take min of them.

for third case : 0's followed by 1's
we will try out all possible strings that we can make

for each idx i, we will form a string that has all zeros till "i'th" idx(including i idx) 
and all 1's after i'th idx.

flips req. for each such oprn = no. of 1's till i'th idx[including i'th idx] +
                                no. of 0's after i'th idx.

try all possible ways and take min. of all cases.
*/
    int minFlipsMonoIncr(string s) {
        unordered_map<char,int> cnt;
        for(char &ch: s) cnt[ch]++;

        int ans=min(cnt['0'],cnt['1']);
        
        int ones=0;//rep cnt of ones till "ith" idx
        for(int i=0; i<s.length(); i++){
            int flips=0;
            
            if(s[i] == '1') ones++;

            //update map : we basically care about no. of 0's after ith idx
            //cnt['0'] tells us no. of 0's after i'th idx
            if(s[i] == '0') cnt[s[i]]--;

            //make cur char 0 if it is one, and all zeros after ith idx to ones
            flips += (ones + cnt['0']);

            ans = min(ans,flips);
        }
        
        return ans;
    }
};