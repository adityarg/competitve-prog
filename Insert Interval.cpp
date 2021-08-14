class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ivs, vector<int>& newivs)
    {
        vector<vector<int>> ans;
        
        if(ivs.size()==0) {ans.push_back(newivs); return ans;}
        int n=ivs.size();
        if(newivs[0]>ivs[n-1][1]) {ivs.push_back(newivs); return ivs;}
        if(newivs[1]<ivs[0][0]) {ivs.insert(ivs.begin(),newivs); return ivs;}
        
        int x=0,y=n;
        for(int i=0;i<ivs.size();i++)
            if(ivs[i][1]>=newivs[0]) {x=i; break;}
        for(int i=0;i<ivs.size();i++)
            if(ivs[i][0]>newivs[1]) {y=i; break;}
                
        for(int i=0;i<x;i++) ans.push_back(ivs[i]);
        vector<int> v; v.push_back(min(ivs[x][0],newivs[0]));
        v.push_back(max(ivs[y-1][1],newivs[1]));
        ans.push_back(v);
        for(int i=y;i<ivs.size();i++) ans.push_back(ivs[i]);
        
        return ans;
    }
};