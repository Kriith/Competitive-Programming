class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, ans = 0, l = 0, r = 0;
        while(l < n){
            while(r < n && (cnt + (nums[r] & 1) <= k)) cnt += nums[r++] & 1;
            ans += r - l;
            cnt -= (nums[l++] & 1);
        }
        // cout<<ans<<' '<<cnt;
        int t = 0; k--;
        if(k < 0) return ans;
        l = r = cnt = 0;
        while(l < n){
            while(r < n && (cnt + (nums[r] & 1) <= k)) cnt += nums[r++] & 1;
            t += r - l;
            cnt -= (nums[l++] & 1);
        }
        return (ans - t);
    }
};