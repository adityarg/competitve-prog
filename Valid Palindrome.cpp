class Solution {
public:
    bool isAlphNum(char c)
    {
        return (c>='a' && c<='z') || (c>='0' && c<='9');
    }
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(i<s.size() && !isAlphNum(s[i])) i++;
            while(j>=0 && !isAlphNum(s[j])) j--;
            if(i<j && s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(string s)
//     {
//         string ns;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]>='a' && s[i]<='z') ns.push_back(s[i]);
//             if(s[i]>='A' && s[i]<='Z') ns.push_back(s[i]-'A'+'a');
//             if(s[i]>='0' && s[i]<='9') ns.push_back(s[i]);
//         }
        
//         for(int i=0;i<ns.size();i++)
//             if(ns[i]!=ns[ns.size()-1-i]) return false;
//         return true;
//     }
// };