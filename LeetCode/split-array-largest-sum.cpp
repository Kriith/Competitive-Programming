class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int m)->bool{
            //cnt = 1 as the last subarray doesn't get counted
            int cursum = 0, cnt = 1;
            for(int i = 0; i < n; i++){
                if(nums[i] > m) return false;
                if(cursum + nums[i] > m) cursum = 0, cnt++;
                cursum += nums[i];
            }
            return (cnt <= k);
        };
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0), ans = r;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(check(m)) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};