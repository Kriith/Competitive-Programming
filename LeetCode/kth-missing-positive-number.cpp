class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1, ans = r + k + 1;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(arr[m] > m + k) ans = m + k, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};

/*
Logic:
arr[m] > m+k tells that the number m+k is missing
if m = 0 and k = 2, and arr[m] = 3 then 3 is missing
*/