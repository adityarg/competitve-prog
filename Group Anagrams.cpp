class Solution {
public:
    vector<int> encoder(string s)
    {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++) v[s[i]-'a']++;
        return v;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<vector<int>, int> m;
        vector<vector<string> > ans;
        for(int i=0;i<strs.size();i++)
        {
            auto e = encoder(strs[i]);
            if(m.find(e)==m.end())
            {
                auto temp=vector<string>{strs[i]};
                ans.push_back(temp); m[e]=ans.size()-1;}
            else ans[m[e]].push_back(strs[i]);
        }
        return ans;
    }
};