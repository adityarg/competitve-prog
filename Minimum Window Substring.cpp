class Solution {
public:
    bool compare(vector<int>& a) // to check if the substring contains "t"
    {
        for(int i=0;i<125;i++)
            if(a[i]>0) return false;
        return true;
    }
    string minWindow(string s, string t)
    {
        vector<int> u(125,0); // keep counts
        
        for(int i=0;i<t.size();i++) u[t[i]]++;
        
        int i=0,j=0,n=s.size();
        int sum=INT_MAX,x=-1,y=-1;
        while(j<n)
        {
            if(compare(u))
            {
                if(sum>j-i) {sum=j-i; x=i; y=j-1;}
                u[s[i]]++;
                i++;
            }
            else
            {
                u[s[j]]--;
                j++;
            }
        }
        
        while(i<n)
        {
            if(compare(u) && sum>j-i) {sum=j-i; x=i; y=j-1;}
            u[s[i]]++;
            i++;
        }
        
        string ans;
        if(x==-1) return ans;
        for(int h=x;h<=y;h++) ans.push_back(s[h]);
        return ans;
    }
};