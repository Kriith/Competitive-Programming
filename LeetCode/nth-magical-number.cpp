class Solution {
    public:
        int nthMagicalNumber(int n, int a, int b) {
            int c = lcm(a, b), mod = 1e9+7;
            auto check = [&](long long m)->bool{
                return (m/a + m/b - m/c >= n);
            };
    
            long long l = 1, r = 1LL*(a+b)*n, ans = 0;
            while(l <= r){
                long long m = (r - l)/2 + l;
                if(check(m)){ ans = m%mod; r = m - 1;}
                else l = m + 1;
            }
            return ans;
        }
    };