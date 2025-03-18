class Solution {
    public:
        bool isPossibleDivide(vector<int>& nums, int k) {
            int n = nums.size();
            map<int, int> mp;
            for(int i = 0; i < n; i++) mp[nums[i]]++;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < n; i++){
                if(mp[nums[i]] > 0){
                    for(int j = nums[i]; j < nums[i] + k; j++){
                        if(mp[j] <= 0) return false;
                        mp[j]--;
                    }
                }
            }
            return true;
        }
    };