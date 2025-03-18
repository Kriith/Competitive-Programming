class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i < n; i++){
                if(nums[i] > 0 && nums[i] <= n){
                    while(nums[i] > 0 &&nums[i] <= n &&nums[i] != i + 1){
                        int x = nums[i];
                        swap(nums[i], nums[x - 1]);
                        if(nums[i] == x) break;
                    }
                }
            }
            int i = 0;
            for(;i < n; i++){
                if(nums[i] != i + 1) break;
            }
            return (i+1);
        }
    };