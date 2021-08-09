// use "map" for better code
// ordered map uses balanced tree, so can search in O(logn) time
// unordered map uses hash table , so can search in time of O(1)
class Solution {
public:
    
    vector<int> twoSum(vector<int>& a, int t)
    {
        map<int,int> m;
        for(int i=0;i<a.size();i++) m.insert({a[i],i});
        
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            auto it = m.find(t-a[i]);
            if(ans.size()==0 && it!=m.end() && it->second!=i)
                {ans.push_back(i); ans.push_back(it->second);}
        }
        return ans;
    }
};