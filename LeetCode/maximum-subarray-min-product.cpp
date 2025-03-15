class Solution {
    public:
        int maxSumMinProduct(vector<int>& nums) {
            int n = nums.size(), mod = 1e9 + 7;
            vector<long long> pf(n + 1, 0LL);
            for(int i = 1; i <= n; i++) pf[i] = pf[i - 1] + nums[i - 1];
            vector<int> l(n, -1), r(n, n);
            stack<int> s;
            for(int i = 0; i < n; i++){
                while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
                if(!s.empty()) l[i] = s.top();
                s.push(i);
            }
            while(!s.empty()) s.pop();
            for(int i = n - 1; i >= 0; i--){
                while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
                if(!s.empty()) r[i] = s.top();
                s.push(i);
            }
            long long area = 0;
            for(int i = 0; i < n; i++)
                area = max(area, 1LL*nums[i]*(pf[r[i]] - pf[l[i] + 1]));
            area = area%mod;
            return area;
        }
    };