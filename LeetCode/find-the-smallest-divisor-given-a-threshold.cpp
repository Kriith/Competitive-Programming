class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int m = (r-l)/2 + l, sum = 0;
            for(int i = 0; i < n; i++) sum += ceil(1.0*nums[i]/m);
            if(sum <= threshold) r = m;
            else l = m + 1;
        }
        return r;
    }
};