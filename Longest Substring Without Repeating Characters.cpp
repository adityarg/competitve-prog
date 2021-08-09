// ordered set uses balance tree (& ubordered set uses hash table)
// stores unique value & values cannot be changed in set
// can be erased though
// can use 2 iterators (i,j) to avoid the usage of queue
// "?" is a conditional operator, eg., 7==5 ? 4 : 3  ; which evaluates to 3, since 7 is not equal to 5
class Solution {
public:
    int max(int a,int b) {return a>b ? a:b;}
    int lengthOfLongestSubstring(string s)
    {
        set<char> g;
        queue<char> q;
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(g.find(s[i])==g.end())
            {
                g.insert(s[i]);
                q.push(s[i]);
            }
            else
            {
                while(s[i]!=q.front()) {g.erase(q.front()); q.pop();}
                g.erase(q.front()); q.pop();
                g.insert(s[i]); q.push(s[i]);
            }
            c = max(c,g.size());
        }
        return c;
    }
};