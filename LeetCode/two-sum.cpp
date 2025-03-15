class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> m;
            vector<int> ans(2, 0);
            for(int i = 0; i < nums.size(); i++){
                if(m.contains(nums[i]) && target == 2*nums[i]){
                    ans = {i, m[nums[i]]};
                    return ans;
                }
                else m[nums[i]] = i;
            }
            for(int i = 0; i < nums.size(); i++){
                cout<<nums[i]<<" "<<(m.contains(target-nums[i]))<<endl;
                if(m.contains(target - nums[i]) && i != m[target - nums[i]]){
                    ans = {i, m[target - nums[i]]};
                    return ans;
                }
            }
            return ans;
        }
    };