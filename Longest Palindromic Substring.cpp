// DP solution - O(n^2) solution

class Solution {
public:
    string longestPalindrome(string a)
    {
        int n=a.size();
        if(n<=1) return a;
        int dp[n+1][n];
        for(int j=0;j<n;j++) dp[1][j]=1;
        for(int j=0;j<n-1;j++)
            if(a[j]==a[j+1]) dp[2][j]=1;
            else dp[2][j]=0;
        
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<n+1-i;j++)
            {
                if(dp[i-2][j+1]==0) dp[i][j]=0;
                else if(dp[i-2][j+1]==1)
                {
                    if(a[j]!=a[i+j-1]) dp[i][j]=0;
                    else dp[i][j]=1;
                }
            }
        }
        
        string s;
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<n+1-i;j++)
                if(dp[i][j]==1)
                {
                    for(int x=j;x<=j+i-1;x++) s.push_back(a[x]);
                    break;
                }
            if(s.size()>0) break;
        }
        return s;
    }
};

// O(n^2) solution by check all odd & even length palindrome separately
// class Solution {
// public:
//     string longestPalindrome(string a)
//     {
//         int n=a.size(), ans=1,x=0,y=0;
        
//         for(int i=0;i<n;i++)
//             for(int l=1;i>=l && i+l<n;l++)
//                 if(a[i-l]==a[i+l] && ans<2*l+1) {ans=max(ans,2*l+1); x=i-l; y=i+l;}
//                 else if(a[i-l]!=a[i+l]) break;
        
//         for(int i=0;i<n-1;i++)
//         {
//             if(a[i]!=a[i+1]) continue;
//             for(int l=0;i>=l && i+l+1<n;l++)
//                 if(a[i-l]==a[i+l+1] && ans<2*l+2) {ans=max(ans,2*l+2); x=i-l; y=i+l+1;}
//                 else if(a[i-l]!=a[i+l+1]) break;
//         }
        
//         // cout<<ans<<"-> "<<x<<" "<<y<<endl;
//         string s;
//         for(int i=x;i<=y;i++) s.push_back(a[i]);
//         return s;
//     }
// };