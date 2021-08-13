// going ring-wise inside the matrix
// i each ring using adjacent swap "n-1-2*i" times to get the required result
class Solution {
public:
    void rotate(vector<vector<int>>& m)
    {
        int n=m.size();
        for(int i=0;i<n/2;i++)
        {
            for(int k=0;k<n-1-2*i;k++)
            {
                int temp=m[i][i];
                for(int j=i+1;j<=n-1-i;j++) swap(temp,m[i][j]);
                for(int j=i+1;j<=n-1-i;j++) swap(temp,m[j][n-1-i]);
                for(int j=n-2-i;j>=i;j--) swap(temp,m[n-1-i][j]);
                for(int j=n-2-i;j>=i;j--) swap(temp,m[j][i]);
            }
        }
    }
};