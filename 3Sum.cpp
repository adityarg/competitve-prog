// used window method to get O(n^2) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a)
    {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int> > ans;
        for(int i=0;i<=n-3;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(a[i]+a[j]+a[k]<0) j++;
                else if(a[i]+a[j]+a[k]>0) k--;
                else
                {
                    int z=ans.size();
                    if(z>0 && ans[z-1][0]==a[i] && ans[z-1][1]==a[j] && ans[z-1][2]==a[k])
                        {j++;k--; continue;}
                    vector<int> v; v.push_back(a[i]); v.push_back(a[j]); v.push_back(a[k]);
                    ans.push_back(v);
                    j++;k--;
                }
            }
        }
        return ans;
    }
};