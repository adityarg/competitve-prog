class Solution {
public:
    int maxProduct(vector<int>& a)
    {
        int n=a.size();
        
        pair<int,int> neg={-1,-1};
        int ans=INT_MIN, prod_so_far=0, curr_len=0;
        bool zero_present=false;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && a[i]==0 && a[i-1]==0) continue;
            if(a[i]==0)
            {
                zero_present=true;
                if(prod_so_far<0 && curr_len>1)
                {
                    int j=neg.first, p1=1;
                    while(j>=0 && a[j]!=0) {p1*=a[j]; j--;}
                    
                    j=neg.second; int p2=1;
                    while(j<n && a[j]!=0) {p2*=a[j]; j++;}
                    
                    if(p1>p2) prod_so_far=prod_so_far/p1;
                    else prod_so_far=prod_so_far/p2;
                }
                ans=max(ans,prod_so_far);
                prod_so_far=0; curr_len=0; neg={-1,-1}; continue;
            }
            
            if(neg.first==-1  && a[i]<0) neg.first=i;
            if(a[i]<0) neg.second=i;
            if(prod_so_far==0) prod_so_far=a[i];
            else prod_so_far*= a[i];
            curr_len++;
        }
        
        if(prod_so_far<0 && curr_len>1)
        {
            int j=neg.first, p1=1;
            while(j>=0 && a[j]!=0) {p1*=a[j]; j--;}

            j=neg.second; int p2=1;
            while(j<n && a[j]!=0) {p2*=a[j]; j++;}

            if(p1>p2) prod_so_far=prod_so_far/p1;
            else prod_so_far=prod_so_far/p2;
        }
        ans=max(ans,prod_so_far);
        if(zero_present) ans=max(0,ans);
        
        return ans;
    }
};