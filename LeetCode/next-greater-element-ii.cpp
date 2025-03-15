class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int> s;
            vector<int> ans(nums.size(), -1);
            for(int i = nums.size() - 1; i >= 0; i--) s.push(nums[i]);
            for(int i = nums.size() - 1; i >= 0; i--){
                while(s.size() > 0 && s.top() <= nums[i]) s.pop();
                if(s.size() > 0) ans[i] = s.top();
                s.push(nums[i]); 
            }
            return ans;
        }
    };