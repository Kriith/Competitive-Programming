class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        while(i < j){
            while(j >= 0 && nums[j] & 1) j--;
            while(i < n && !(nums[i]%2)) i++;
            if(i < j) swap(nums[i], nums[j]);
        }
        return nums;
    }
};