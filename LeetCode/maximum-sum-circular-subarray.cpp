class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int n = nums.size(), curmx = 0, curmn = 0, mxsm = nums[0], mnsm = nums[0], totsm = 0;
            for(int i = 0; i < n; i++){
                curmx = max(curmx + nums[i], nums[i]);
                mxsm = max(curmx, mxsm);
                curmn = min(curmn + nums[i], nums[i]);
                mnsm = min(curmn, mnsm);
                totsm += nums[i];
            }
            if(totsm == mnsm)
                return mxsm;
            else return max(mxsm, totsm - mnsm);
        }
    };