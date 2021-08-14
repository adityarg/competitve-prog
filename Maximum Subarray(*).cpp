// kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& a)
    {
        int ans=INT_MIN,max_ending_so_far=0;
        for(int i=0;i<a.size();i++)
        {
            max_ending_so_far+= a[i];
            
            ans=max(ans,max_ending_so_far);
            
            if(max_ending_so_far<0) max_ending_so_far=0;
        }
        return ans;
    }
};


// used divide-conquer method to get O(nlogn) solution
// class Solution {
// public:
//     int divide_n_conquer(vector<int>& a, int l, int r)
//     {
//         if(l==r) return a[l];
//         if(l>r) return 0;
        
//         int m=(l+r)/2;
//         int ans= max(divide_n_conquer(a,l,m),divide_n_conquer(a,m+1,r));
        
//         int s=0,max1=INT_MIN;
//         for(int i=m;i>=l;i--) {s+=a[i]; max1=max(max1,s);}
//         s=0; int max2=INT_MIN;
//         for(int i=m+1;i<=r;i++) {s+=a[i]; max2=max(max2,s);}
//         ans = max(ans,max1+max2);
        
//         return ans;
        
//     }
//     int maxSubArray(vector<int>& a)
//     {
//         int n=a.size();
//         return divide_n_conquer(a,0,n-1);
//     }
// };