class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size(), tot = 0;
        for(int i = 0; i < n; i++) tot += arr[i];
        if(sum > tot) return false;
        vector<bool> dp(tot+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = tot; j >= arr[i]; j--)
                dp[j] = dp[j] || dp[j - arr[i]];
        return dp[sum];
    }
};