//Brute force solution, 2 extra vectors
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, larger;
        int n = nums.size(), pivotCount = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                smaller.push_back(nums[i]);
            }
            else if(nums[i] > pivot) {
                larger.push_back(nums[i]);
            }
            else {
                pivotCount++;
            }
        }
        
        while(pivotCount--) {
            smaller.push_back(pivot);
        }

        smaller.insert(smaller.end(), larger.begin(), larger.end());
        return smaller;
    }
};

//One pass, one extra vector solution
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), l = 0, r = n - 1; 
        vector<int> ans(n);

        for(int i = 0, j = n - 1; i < n; i++, j--) {
            if(nums[i] < pivot) {
                ans[l++] = nums[i];
            }
            if(nums[j] > pivot) {
                ans[r--] = nums[j];
            }
        }

        while(l <= r) {
            ans[l++] = pivot;
        }

        return ans;
    }
};