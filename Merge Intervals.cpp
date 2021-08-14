class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[0]<b[0] || (a[0]==b[0] && a[1]<b[1])) return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int>> ans; ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            int x1=ans.back()[0], y1=ans.back()[1];
            int x2=intervals[i][0], y2=intervals[i][1];
            
            if(y1<x2) ans.push_back(intervals[i]);
            else ans.back()[1]=max(ans.back()[1],y2);
        }
        return ans;
    }
};