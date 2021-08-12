class Solution {
public:
    bool isValid(string s)
    {
        stack<char> g;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') g.push(s[i]);
            else
            {
                if(g.empty()) return false;
                char c = g.top();
                if((s[i]==')' && c=='(') || (s[i]=='}' && c=='{') || (s[i]==']' && c=='['))
                    g.pop();
                else
                    return false;
            }
        }
        if(g.empty()) return true;
        return false;
    }
};