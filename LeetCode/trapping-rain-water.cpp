class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size(), lmax = 0, rmax = 0, ans = 0, l = 0, r = n - 1;
            while(l < r){
                if(height[l] <= height[r]){
                    if(height[l] < lmax) ans += lmax - height[l];
                    else lmax = height[l];
                    l++;
                }
                else{
                    if(height[r] < rmax) ans += rmax - height[r];
                    else rmax = height[r];
                    r--;
                }
            }
            return ans;
        }
    };