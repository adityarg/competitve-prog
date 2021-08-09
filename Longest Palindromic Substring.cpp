class Solution {
public:
    string longestPalindrome(string a)
    {
        int n=a.size(), ans=1,x=0,y=0;
        
        for(int i=0;i<n;i++)
            for(int l=1;i>=l && i+l<n;l++)
                if(a[i-l]==a[i+l] && ans<2*l+1) {ans=max(ans,2*l+1); x=i-l; y=i+l;}
                else if(a[i-l]!=a[i+l]) break;
        
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=a[i+1]) continue;
            for(int l=0;i>=l && i+l+1<n;l++)
                if(a[i-l]==a[i+l+1] && ans<2*l+2) {ans=max(ans,2*l+2); x=i-l; y=i+l+1;}
                else if(a[i-l]!=a[i+l+1]) break;
        }
        
        // cout<<ans<<"-> "<<x<<" "<<y<<endl;
        string s;
        for(int i=x;i<=y;i++) s.push_back(a[i]);
        return s;
    }
};