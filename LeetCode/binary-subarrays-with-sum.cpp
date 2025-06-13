class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0, sum = 0, r = 0, l = 0;
        while(l < n){
            while(r < n && (sum + nums[r]) <= goal) sum += nums[r++];
            ans += r - l;
            sum -= nums[l++];
        }
        sum = r = l = 0; 
        int t = 0;
        goal--;
        while(l < n){
            if(goal < 0) break;
            while(r < n && sum + nums[r] <= goal) sum += nums[r++];
            t += r - l;
            sum -= nums[l++];
        }
        ans -= t;
        return ans;
    }
};