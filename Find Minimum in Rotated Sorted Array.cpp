class Solution {
public:
    int findMin(vector<int>& a)
    {
        int n=a.size();
        if(n==1 || a[0]<a[n-1]) return a[0];
        
        int l=0,r=n-1;
        while(l<r)
        {
            int m=(l+r)/2;
            if(m>0 && a[m]<a[m-1]) return a[m];
            else if(a[m]>=a[0]) l=m+1;
            else r=m-1;
        }
        return a[l];
    }
};