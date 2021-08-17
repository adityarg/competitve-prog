// Time = O(mn) & Space = (1)
// EXPLAINATION
// The idea is to use first row and first column as indicator, if we need to set the whole corresponding column or row to zeros. We also keep r1 andc1` variables: do we need to update first column and/or first row in the end.
// 1. Create r1 and c1.
// 2. Iterate through our matrix and if we see that for if element M[i][j] is equal to 0, we put both elements M[i][0] and M[0][j] to 0.
// 3. Now, we updated all elements in first row and column, so we iterate our matrix once again: and if we see that one of elements M[i][0] or M[0][j] equal to 0, we make M[i][j] equal to0`.
// 4. Finally, we need to update first row and column, so we make them 0, if we have indicator r1 for row and c1 for column
// Link: https://leetcode.com/problems/set-matrix-zeroes/discuss/1400861/Python-O(mn)O(1)-timespace-solution-explained
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat)
    {
        int m=mat.size(), n=mat[0].size();
        int r=0,c=0;
        for(int i=0;i<m;i++) if(mat[i][0]==0) r=1;
        for(int j=0;j<n;j++) if(mat[0][j]==0) c=1;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==0) {mat[i][0]=0; mat[0][j]=0;}
        
        for(int i=1;i<m;i++)
            if(mat[i][0]==0)
                for(int j=0;j<n;j++) mat[i][j]=0;
        
        for(int j=1;j<n;j++)
            if(mat[0][j]==0)
                for(int i=0;i<m;i++) mat[i][j]=0;
        
        if(r==1) for(int i=0;i<m;i++) mat[i][0]=0;
        if(c==1) for(int j=0;j<n;j++) mat[0][j]=0;
    }
};

// Time = O(mn) & Space = (m+n)
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& mat)
//     {
//         int m=mat.size(), n=mat[0].size();
        
//         vector<int> row,col;
//         for(int i=0;i<m;i++)
//             for(int j=0;j<n;j++)
//                 if(mat[i][j]==0) {row.push_back(i); col.push_back(j);}
        
//         for(auto i:row)
//             for(int j=0;j<n;j++) mat[i][j]=0;
        
//         for(auto j:col)
//             for(int i=0;i<m;i++) mat[i][j]=0;
//     }
// };