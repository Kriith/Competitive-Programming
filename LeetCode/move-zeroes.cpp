class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int ind = -1, n = nums.size();
            for(int i = 0; i < n; i++){
                if(nums[i] != 0){
                    ind++;
                    swap(nums[i], nums[ind]);
                }
            }
        }
    };