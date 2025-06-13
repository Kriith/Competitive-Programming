class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans1 = 0, ans2 = 0, curr = 0, prev = 0;
        for(int i = 1; i < n; i++){
            int t = curr;
            curr = max(prev + nums[i], curr);
            prev = t;
        }
        ans1 = max(curr, prev);
        curr = prev = 0;
        for(int i = 0; i < n - 1; i++){
            int t = curr; 
            curr = max(curr, prev + nums[i]);
            prev = t;
        }
        ans2 = max(curr, prev);
        return max(ans1, ans2);
    }
};