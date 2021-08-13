// Time Complexity Explaination: https://leetcode.com/problems/combination-sum/discuss/742449/Explanation-of-Time-Complexity
// Simple Brute Force with little trick to ensure "no duplicity"
// trick is obvious for the author, hehe!
// Time Complexity: O(len(candidates)^target)

class Solution {
public:
    int dp[30][501];
    void func(vector<int>& can, int k, int curr_sum, vector<vector<int> > &ans, vector<int>& v)
    {
        if(curr_sum==0) {ans.push_back(v);}
        if(curr_sum<0) return;
        
        for(int i=k;i<can.size();i++)
        {
            v.push_back(can[i]);
            func(can,i,curr_sum-can[i],ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int trg)
    {
        vector<vector<int> > ans;
        for(int i=0;i<can.size();i++)
            for(int j=1;j<=trg;j++) dp[i][j]=-1;
        
        vector<int> v;
        for(int i=0;i<can.size();i++)
        {
            v.push_back(can[i]);
            func(can,i,trg-can[i],ans,v);
            v.pop_back();
        }
        return ans;
    }
};