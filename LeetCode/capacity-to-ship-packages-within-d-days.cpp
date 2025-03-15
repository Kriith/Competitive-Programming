class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size(), l = *max_element(weights.begin(), weights.end()), r = 1e9, ans = l;
            while(l <= r){
                int m = (r - l)/2 + l, req = 1, cursum = 0;
                for(int i = 0; i < n; i++){
                    if(cursum + weights[i] > m){ req++; cursum = 0; }
                    cursum += weights[i];
                }
                if(req <= days){ ans = m; r = m - 1; }
                else l = m + 1;
            }
            return ans;
        }
    };