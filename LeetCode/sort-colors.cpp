//1 pass approach
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int i = 0, l = 0, r = nums.size() - 1;
            while(i <= r){
                if(nums[i] < 1) swap(nums[i++], nums[l++]);
                else if(nums[i] > 1) swap(nums[i], nums[r--]);
                else i++;
            }
        }
    };

//2 pass approach
// class Solution {
//     public:
//         void sortColors(vector<int>& nums) {
//             int n = nums.size(), j = 0;
//             for(int i = 0; i < n; i++){
//                 if(nums[i] < 1){
//                     swap(nums[i], nums[j]);
//                     j++;
//                 }
//             }
//             j = n - 1;
//             for(int i = n - 1; i >= 0; i--){
//                 if(nums[i] > 1){
//                     swap(nums[i], nums[j]);
//                     j--;
//                 }
//             }
//         }
//     };