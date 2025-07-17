class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(l == r) return nums[l];
        while(l <= r){
            int m = (r-l)/2 + l;
            if(m == 0){
                if(nums[m] != nums[m+1]) return nums[m];
                l = m + 1;
            }
            else if(m == nums.size() - 1){
                if(nums[m] != nums[m-1]) return nums[m];
                r = m - 1;
            }
            else{
                if(nums[m] == nums[m-1]){
                    if(m & 1) l = m + 1;
                    else r = m - 1;
                }
                else if(nums[m] == nums[m+1]){
                    if(m & 1) r = m - 1;
                    else l = m + 1;
                }
                else return nums[m];
            }
        }
        return -1;
    }
};