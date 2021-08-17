// A beautiful solution: Time:O(n) & Space:O(1)
// EXPLAININATION:
// Use dynamic programming for this problem, where we keep 3 values on each step:
// 1. dp[0] is total numbers to decode number s[:i].
// 2. dp[1] is number of ways to decode number s[:i], if it ends with 1 and last digit is part of 2-digit number. This is important point.
// 3. dp[2] is number of ways to decode number s[:i], if it ends with 2 and last digit is part of 2-digit number.
//
// Now, we need to understand how to update our numbers:
// For dp_new[0] we can have 3 options: if last digit is more than 0, than we can take it as 1-digit number (by definition each part is number between 1 and 26). Also, we can take last number as 2-digit number if it starts with 1: this is exactly dp[1]. and if it starts with 2 and last digit is less or equal to 6.
// For dp_new[1] we have only one option: we need to have last symbol equal to 1.
// Similar for dp_new[2], we need to have last symbol equal to 2.
// Link: https://leetcode.com/problems/decode-ways/discuss/987013/Python-O(n)-timeO(1)-space-dp-explained
class Solution {
public:
    int numDecodings(string s)
    {   
        int n=s.size();
        vector<int> dp({1,0,0});
        for(int i=0;i<s.size();i++)
        {
            vector<int> dp_new({0,0,0});
            dp_new[0]  = (s[i]>'0')*dp[0] + dp[1] + (s[i]<='6')*dp[2];
            dp_new[1]  = (s[i]=='1')*dp[0];
            dp_new[2]  = (s[i]=='2')*dp[0];
            dp = dp_new;
        }
        return dp[0];
    }
};

// My solution: Time:O(n) & Space:O(n)
// class Solution {
// public:
//     int numDecodings(string s)
//     {   
//         int n=s.size();
//         if(s[0]=='0') return 0;
//         if(n==1) return 1;
        
//         vector<pair<int,int> > dp(n,{0,0});
        
//         // initialise 0th index
//         if(s[0]!='0') dp[0].first=1;
//         if(n>1 && (s[0]-'0')*10+(s[1]-'0')<=26) dp[0].second=1;
        
//         // initialise 1st index
//         if(n>1 && s[1]!='0') dp[1].first=1;
//         dp[1].first = dp[1].first*dp[0].first;
//         if(n>2 && s[1]!='0' && stoi(s.substr(1,2))<27) dp[1].second=1;
//         dp[1].second = dp[1].second*dp[0].first;
        
//         for(int i=2;i<n;i++)
//         {
//             if(s[i]!='0') dp[i].first=1;
//             dp[i].first = (dp[i].first)*(dp[i-1].first + dp[i-2].second);
            
//             if(i<n-1 && s[i]!='0' && stoi(s.substr(i,2))<27) dp[i].second=1;
//             dp[i].second = (dp[i].second)*(dp[i-1].first + dp[i-2].second);
//         }
//         return dp[n-1].first + dp[n-2].second;
//     }
// };