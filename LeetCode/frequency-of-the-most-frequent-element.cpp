class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1;
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int l = 0, r = 1; r < n; r++){
            sum += 1LL*(nums[r] - nums[r-1])*(r-l);
            while(sum > k)  sum -= nums[r] - nums[l], l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};