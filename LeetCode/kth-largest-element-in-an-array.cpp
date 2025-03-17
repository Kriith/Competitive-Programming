class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
    
            auto partition = [&](int left, int right)->int{
                int pivot = nums[right], index = left - 1;
                for(int i = left; i < right; i++){
                    if(nums[i] < pivot){
                        index++;
                        swap(nums[i], nums[index]);
                    }
                }
                index++;
                swap(nums[index], nums[right]);
                return index;
            };
    
            int left = 0, right = n - 1;
            while(left < right){
                int p = rand()%(right - left + 1) + left;
                swap(nums[p], nums[right]);
                int pivot = partition(left, right);
                if(pivot == n - k) return nums[pivot];
                else if(pivot > n - k) right = pivot - 1;
                else left = pivot + 1;
            }
            return nums[n - k];
        }
    };