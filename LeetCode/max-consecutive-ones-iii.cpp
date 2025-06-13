class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, cnt = 0;
        for(int l = 0, r = 0; r < n; r++){
            if(!nums[r]) cnt++;
            while(cnt > k){
                if(!nums[l]) cnt--;
                l++;
            }
            ans = max(r - l + 1, ans);
        }
        return ans;
    }
};