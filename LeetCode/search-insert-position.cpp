class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int ans = 0, l = 0, r = nums.size() - 1;
            while(l <= r){
                int m = (r-l)/2 + l;
                if(nums[m] == target){ ans = m; break; }
                else if(nums[m] < target){ ans = m + 1; l = m + 1; }
                else{ 
                    r = m - 1; 
                    if(m == 0) ans = 0;
                    else if(nums[m - 1] > target) ans = m - 1;
                    else ans = m;
                }
            }
            return ans;
        }
    };