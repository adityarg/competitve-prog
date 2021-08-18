class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minn=INT_MAX,ans = 0;
        
        for(int i=0;i<prices.size();i++)
            if(prices[i]<minn) minn = prices[i];
            else if(prices[i]-minn>ans) ans = prices[i]-minn;
        
        return ans;
    }
};