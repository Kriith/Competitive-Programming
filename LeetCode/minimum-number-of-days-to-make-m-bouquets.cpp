class Solution {
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            if(1LL*m*k > bloomDay.size()) return -1;
    
            int ans = -1, l = 0, r = *max_element(bloomDay.begin(), bloomDay.end()), n = bloomDay.size();
    
            while(l <= r){
                int mid = (r - l)/2 + l;
                vector<bool> a(n, 0);
    
                for(int i = 0; i < n; i++)
                    if(bloomDay[i] <= mid) a[i] = 1;
                int cur = 0, req = m;
                for(int i = 0; i < n; i++){
                    if(a[i]){
                        cur++;
                        if(cur >= k){ req--; cur = 0;}
                    }
                    else cur = 0;
                }
    
                if(req > 0) l = mid + 1;
                else { ans = mid; r = mid - 1; }
            }
            return ans;
        }
    };