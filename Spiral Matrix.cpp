class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a)
    {
        int m=a.size(), n=a[0].size();
        vector<int> ans;
        float x=min(m,n);
        for(int i=0;i<ceil(x/2);i++)
        {
            for(int j=i;j<=n-1-i;j++) ans.push_back(a[i][j]);
            for(int j=i+1;j<=m-1-i;j++) ans.push_back(a[j][n-1-i]);
            if(i!=m-1-i) for(int j=n-2-i;j>=i;j--) ans.push_back(a[m-1-i][j]);
            if(i!=n-1-i) for(int j=m-2-i;j>i;j--) ans.push_back(a[j][i]);
        }
        return ans;
    }
};