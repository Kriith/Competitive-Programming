class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(2, 0);
        for(int i = 0; i < 2; i++, k--){
            int l = 0, r = 0, curr = 0;
            vector<int> cnt(n+1, 0);
            while(l < n){
                while(r < n && curr + (cnt[nums[r]] == 0) <= k){
                    curr += (cnt[nums[r]] == 0);
                    cnt[nums[r++]]++;
                }
                ans[i] += r - l;
                curr -= (--cnt[nums[l++]] == 0);
            }
        }
        return ans[0] - ans[1];
    }
};