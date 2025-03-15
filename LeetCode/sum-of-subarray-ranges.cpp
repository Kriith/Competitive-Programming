class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            int n = nums.size();
            vector<int> nse(n, n), psee(n, -1), nge(n, n), pgee(n, -1);
            stack<int> sts, stg;
            for(int i = 0; i < n; i++){
                while(!sts.empty() && nums[sts.top()] > nums[i]) sts.pop();
                while(!stg.empty() && nums[stg.top()] < nums[i]) stg.pop();
                if(!sts.empty()) psee[i] = sts.top();
                if(!stg.empty()) pgee[i] = stg.top();
                sts.push(i); stg.push(i);
            }
            while(!sts.empty()) sts.pop();
            while(!stg.empty()) stg.pop();
            for(int i = n - 1; i >= 0; i--){
                while(!sts.empty() && nums[sts.top()] >= nums[i]) sts.pop();
                while(!stg.empty() && nums[stg.top()] <= nums[i]) stg.pop();
                if(!sts.empty()) nse[i] = sts.top();
                if(!stg.empty()) nge[i] = stg.top();
                sts.push(i); stg.push(i);
            }
            long long sum = 0;
            for(int i = 0; i < n; i++)
                sum += (1LL*(nge[i] - i)*(i - pgee[i])*nums[i]) - (1LL*(nse[i] - i)*(i - psee[i])*nums[i]);
            return sum;
        }
    };