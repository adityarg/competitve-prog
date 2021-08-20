class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> g;
        
        for(int i=0;i<nums.size();i++) g.insert(nums[i]);
        
        int ans=0;
        for(auto n:g)
        {
            int s=1, curr=n+1;
            while(g.find(curr)!=g.end()) {g.erase(curr); curr++; s++;}
            curr=n-1;
            while(g.find(curr)!=g.end()) {g.erase(curr); curr--; s++;}
            
            ans=max(ans,s);
        }
        
        return ans;
    }
};

// Time: O(nlogn) used sorting
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums)
//     {
//         if(nums.size()==0) return 0;
//         sort(nums.begin(),nums.end());
//         int ans=1,max_so_far=1;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i-1]) continue;
//             if(nums[i]-nums[i-1]==1) {max_so_far++; ans=max(ans,max_so_far);}
//             else max_so_far=1;
//         }
//         return ans;
//     }
// };