// used two pointer method to get O(n) solution
// EXPLANATION:
//if h[l] is lower and we move r to left then two cases may happen:
    // case 1: h[r] gets higher, but the size of container remains same because height of container is 
    //          min(h[l],h[r]);
    // case 2: h[r] gets smaller ,size of container will get smaller;
    // so this is not the right move, as the size of container has no chance of getting bigger;
    // So if h[l] is lower then we move it to the right . We may get higher or lower h[l]
    //So we have a chance of getting larger container
class Solution {
public:
    int maxArea(vector<int>& h)
    {
        int ans=INT_MIN, n=h.size();
        int l=0, r=n-1;
        while(l<r)
        {
            if(h[l]<h[r]) {ans=max(ans,h[l]*(r-l)); l++;}
            else {ans=max(ans,h[r]*(r-l)); r--;}
        }
        return ans;
    }
};