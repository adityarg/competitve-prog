// smart solutioon to avoid overflow
// at each step we are storing both numerator & denominator
// and we divide both of them by their gcd to avoid overflow
// Link: https://www.geeksforgeeks.org/program-to-calculate-the-value-of-ncr-efficiently/
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int ans=1; m--; n--;
        
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        int p = 1, k = 1;

        // C(n, r) == C(n, n-r),
        // choosing the smaller value
        if(m>n) swap(m,n);

        if(m!=0)
        {
            while(m)
            {
                p *= (m+n); k *= m;

                // gcd of p, k
                int g = __gcd(p, k);

                // dividing by gcd, to simplify product division
                // by their gcd saves from the overflow
                p /= g; k /= g;

                m--;
            }
        }

        else
            p = 1;
        return p;
    }
};

// Find nCr in O(r) time & O(1) space
// EXPLANATION:
// Change r to n-r if r is greater than n-r
// Run a loop from 0 to r-1
// In each iteration, update ans as (ans*(n-i))/(i+1) where i is the loop counter
// Link: https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
//
// class Solution {
// public:
//     int uniquePaths(int m, int n)
//     {
//         int ans=1; m--; n--;
        
//         if(m>n) swap(m,n);
        
//         for(int i=0;i<m;i++)
//         {
//             ans *= (m+n-i);
//             ans /= (i+1);
//         }
//         return ans;
//     }
// };