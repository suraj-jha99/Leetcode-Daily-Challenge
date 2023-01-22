#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//app 1:based on dp partitioning concept
    bool isPalind(int i,int j,string s){
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }

        return true;
    }

    void f(int idx,string s,vector<vector<string>> &res,vector<string> &ans){
        if(idx == s.size()){
            res.push_back(ans);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPalind(idx,i,s)){
                ans.push_back(s.substr(idx,i-idx+1));
                //call next fun
                f(i+1,s,res,ans);
                //backtrack
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();

        vector<vector<string>> res;
        vector<string> ans;
        f(0,s,res,ans);

        return res;
    }
};