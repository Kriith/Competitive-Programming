class Solution {
public:
    using ll = long long;
    int repeatedStringMatch(string a, string b) {
        if(b == "") return 0;
        int cnt = 1;
        string aa = a;
        while(aa.size() < b.size()) aa += a, cnt++;
        if(rabin(b, aa)) return cnt;
        aa += a, cnt++;
        if(rabin(b, aa)) return cnt;
        return -1;
    }

private:
    bool rabin(string& s, string& t){
        if(s == "" || t == "") return 0;
        int ss = s.size(), tt = t.size(), p = 31;
        ll mod = 1e9 + 9, hs = 0;
        vector<ll> ht(tt+1, 0), pow(max(ss, tt));
        pow[0] = 1;
        for(int i = 1; i < pow.size(); i++) pow[i] = (pow[i-1]*p)%mod;
        for(int i = 0; i < tt; i++) 
            ht[i+1] = (ht[i] + (t[i] - 'a' + 1)*pow[i])%mod;
        for(int i = 0; i < ss; i++) 
            hs = (hs + (s[i] - 'a' + 1)*pow[i])%mod;
        for(int i = 0; i + ss <= tt; i++){
            ll curh = (ht[i+ss] - ht[i] + mod)%mod;
            if(curh == hs*pow[i]%mod) return 1;
        }
        return 0;
    }
};