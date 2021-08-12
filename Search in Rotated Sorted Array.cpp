class Solution {
public:
    int binary_search(vector<int>& a, int target, int l,int r)
    {
        while(l<r)
        {
            int m=(l+r)/2;
            if(a[m]==target) return m;
            else if(a[m]>target) r=m-1;
            else l=m+1;
        }
        if(l==r && a[l]==target) return l;
        return -1; // not found
    }

// Implemented by trying to find tthe "pivot" using binary search
    int search(vector<int>& a, int target)
    {
        int n=a.size();
        if(n==1)
            if(a[0]==target) return 0;
            else return -1;
        int l=0, r=n-1, pivot;
        while(l<r)
        {
            pivot = (l+r)/2;
            if((pivot<n-1 && a[pivot]>a[pivot+1]) || pivot==n-1) break;
            else if(a[pivot]>=a[0]) l=pivot+1;
            else r=pivot-1;
        }
        pivot=(l+r)/2;
        
        if(target>=a[0]) return binary_search(a,target,0,pivot);
        else return binary_search(a,target,pivot+1,n-1);
    }
};