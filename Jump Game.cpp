// try avoid using a extra array tto keep record for better solution (leetcode-wise)
class Solution {
public:
    bool canJump(vector<int>& a)
    {
        int n=a.size();
        if(n==1) return true;
        
        int m=0;
        for(int i=0;i<n-1;i++)
        {
            if(i>m) break; // all points here and afterwards are not reachable
            int f = min(i+a[i],n-1);
            m=max(m,f);
            if(m==n-1) return true;
        }
        return false;
    }
};