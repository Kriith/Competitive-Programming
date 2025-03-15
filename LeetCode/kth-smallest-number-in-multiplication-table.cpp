class Solution {
    public:
        int findKthNumber(int m, int n, int k) {
            int l = 1, r = m*n, ans = 0;
            while(l <= r){
                int mid = (r - l)/2 + l;
                int cnt = 0;
                for(int i = 1; i <= m; i++)
                    cnt += min(n, mid/i);
                if(cnt < k) l = mid + 1;
                else{ ans = mid; r = mid - 1; }
            }
            return ans;
        }
    };