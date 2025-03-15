class Solution {
    public:
        long long maxRunTime(int n, vector<int>& batteries){
            int m = batteries.size();
            auto check = [&](long long mid) -> bool{
                long long sum = 0;
                for(int i = 0; i < m; i++)
                    sum += min(1LL*batteries[i], mid);
                cout<<mid<<" "<<sum<<endl;
                return (sum >= (n*mid));
            };
    
            long long l = 0, r = 0, ans = 0;
            for(int i = 0; i < m; i++) r += batteries[i];
            while(l <= r){
                long long mid = (r - l)/2 + l;
                if(check(mid)){ ans = mid; l = mid + 1; }
                else r = mid - 1;
            }
            return ans;
        }
    };