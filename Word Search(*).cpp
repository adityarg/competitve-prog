// Iteratie verson
// Do it again by yourself
// Link: https://leetcode.com/problems/word-search/discuss/916921/C%2B%2B-iterative-short-%2B-meaningful-var-names-for-easier-understanding
class Solution {
public:
    bool exist(vector<vector<char>>& board, string w)
    {
        int m=board.size(), n=board[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                vector<vector<bool> > vis(m,vector<bool>(n,false));
                stack<tuple<int,int,int> > g; g.push({i,j,0});
                while(!g.empty())
                {
                    auto [x,y,k]=g.top();
                    
                    if(vis[x][y] || board[x][y]!=w[k])
                        {g.pop(); vis[x][y]=false; continue;}
                    
                    vis[x][y]=true;
                    if(k==w.size()-1) return true;
                    
                    if(x+1<m  && !vis[x+1][y]) g.push({x+1,y,k+1});
                    if(x-1>=0 && !vis[x-1][y]) g.push({x-1,y,k+1});
                    if(y+1<n  && !vis[x][y+1]) g.push({x,y+1,k+1});
                    if(y-1>=0 && !vis[x][y-1]) g.push({x,y-1,k+1});
                }
            }
        return false;
    }
};

// Recursive Version
// class Solution {
// public:
//     int m,n, dp[6][6];
//     bool search(vector<vector<char>>& board, int i, int j, string w, int k)
//     {
//         if(k==w.size()) return true;
//         if(i==m || j==n || i==-1 || j==-1 || board[i][j]!=w[k] || dp[i][j]==1)
//             return false;
//         dp[i][j]=1;
        
//         bool a1 = search(board,i+1,j,w,k+1);
//         bool a2 = search(board,i,j+1,w,k+1);
//         bool a3 = search(board,i-1,j,w,k+1);
//         bool a4 = search(board,i,j-1,w,k+1);
        
//         dp[i][j]=0;
//         if(a1 || a2 || a3 || a4) return true;
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string w)
//     {
//         m=board.size(); n=board[0].size();
//         for(int i=0;i<6;i++)
//             for(int j=0;j<n;j++) dp[i][j]=0;
        
//         for(int i=0;i<m;i++)
//             for(int j=0;j<n;j++)
//                 if(search(board,i,j,w,0)) return true;
        
//         return false;
//     }
// };