class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(sum + 1, 0);
        dp[nums[0]] = 2;
        //start from 1 as we dont want to count nums[0] twice
        for(int i = 1; i < n; i++){
            for(int j = sum - nums[i]; j >= 0; j--)
                dp[j + nums[i]] |= (dp[j]<<1);
        }
        for(int i = 1; i < n; i++){
            if((sum*i)%n == 0){
                int s = (sum*i)/n;
                if(dp[s] & (1<<i)) return 1;
            }
        }
        return 0;
    }
};

/*
dp bitmask: o(n*sum), o(n)
dp[s] stores the bitmask of all the lengths possible for s
lets say for 56, we can have 3 subsets of lenghts 1, 3, 4
then dp[56] = 000..0011010
dp[j + nums[i]] |= dp[j] << 1
this statement updates dp[s] accordingly for each nums[i]
*/