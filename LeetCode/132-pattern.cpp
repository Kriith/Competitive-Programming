class Solution {
    public:
        bool find132pattern(vector<int>& nums) {
            int n = nums.size(), mn = nums[0];
            stack<pair<int, int>> s;
            for(int i = 1; i < n; i++){
                while(!s.empty() && nums[i] >= s.top().first) s.pop();
                if(!s.empty() && nums[i] > s.top().second) return true;
                mn = min(mn, nums[i]);
                s.push({nums[i], mn});
            }
            return false;
        }
    };