class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};