class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum & 1) return false;
        sum /= 2;
        vector<bool> dp1(sum+1, 0), dp2(sum+1, 0);
        dp1[0] = dp2[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= sum; j++){
                dp2[j] = dp1[j];
                if(j >= nums[i]) dp2[j] = dp2[j] || dp1[j - nums[i]];
            }
            dp1 = dp2;
        }
        return dp2[sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum & 1) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};

//bitset soln, dp<<i adds i value to dp and orring it with dp gives all possible sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum & 1) return false;
        sum /= 2;
        bitset<10001> dp(1);
        for(auto i : nums) dp |= dp<<i;
        return dp[sum];
    }
};