class Solution {
public:
    //blind 75 que
    vector<vector<int>> insert(vector<vector<int>>& intr, vector<int>& newIntr) {
        vector<vector<int>> ans;
        
        for(int i=0; i<intr.size(); i++){
            //if new interval lies to the left of cur interval[i]
            if(newIntr[1] < intr[i][0]){
                ans.push_back(newIntr);
                //copy rest of intervals and return 
                for(int j=i; j<intr.size(); j++) ans.push_back(intr[j]);
                return ans;
            }
            
            //if new intr lies to the right of cur int[i]
            else if(newIntr[0] > intr[i][1]){
                ans.push_back(intr[i]);
            }
            
            //intervals overlap ==> update new interval by merging intervals
            else{
                newIntr[0] = min(newIntr[0],intr[i][0]);
                newIntr[1] = max(newIntr[1],intr[i][1]);
            }
        }
        
        ans.push_back(newIntr); //in case the first if stat. does not execute
        return ans;
    }
};