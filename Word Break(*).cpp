// tried the brute force
// tried implemeneting dp i brute force
// success at dp
// try again sir!
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n=s.size(); bool dp[n+1];
        unordered_set<string> m;
        for(int i=0;i<wordDict.size();i++) m.insert(wordDict[i]);
        
        for(int i=0;i<n;i++) dp[i]=false;
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--)
            for(int len=1;len<=n-i;len++)
                if(m.find(s.substr(i,len))!=m.end() && dp[i+len]) {dp[i]=1; break;}
        
        return dp[0];
    }
};