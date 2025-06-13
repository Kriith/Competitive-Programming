class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2, tot = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> lsum(n+1), rsum(n+1);
        for(int i = 0; i < (1<<n); i++){
            int ls, rs, cnt;
            ls = rs = cnt = 0;
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    ls += nums[j];
                    rs += nums[n + j];
                    cnt++;
                }
            }
            lsum[cnt].push_back(ls);
            rsum[cnt].push_back(rs);
        }
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++){
            sort(rsum[n-i].begin(), rsum[n-i].end());
            for(auto &j: lsum[i]){
                int t = (tot - 2*j)/2;
                // cout<<t<<' '<<j<<' '<<i<<endl;
                auto it = lower_bound(rsum[n-i].begin(), rsum[n-i].end(), t);
                if(it != rsum[n-i].end()){
                    ans = min(ans, abs(tot - 2*(j + *(it))));
                    // cout<<t<<' '<<j<<' '<<i<<' '<<(*it)<<' '<<ans<<' '<<(abs(tot - 2*(j + *(it))))<<endl;
                }
                if(it != rsum[n-i].begin()){
                    ans = min(ans, abs(tot - 2*(j + *(--it))));
                    // cout<<t<<' '<<j<<' '<<i<<' '<<(*it)<<' '<<ans<<' '<<(abs(tot - 2*(j + *(it))))<<endl;
                }
            }
        }
        return ans;
    }
};