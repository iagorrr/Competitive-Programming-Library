// iagorrr ;)

class Solution {
public:
    int dp[(int)1e5];
    int solve(vector<int> a, int k){
        if(dp[k] != -1) return dp[k];
        
        dp[k] = 0;
        for(int i = 0; i < (int)a.size(); ++i)
            if(k-a[i] >= 0)
                dp[k] += solve(a, k-a[i]);
        
        return dp[k];
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        int ans = solve(nums, target);
        return ans;
    }
};

// Accepted.