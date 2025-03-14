#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using pi = pair<int, int>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "

void solve(){
    string s;
    cin>>s;
    ll n = s.size();
    ll pf[n];
    pf[0] = (s[0] == '1')?1:0;
    lopp(i, n){
        if(s[i] == '1')
            pf[i] = pf[i-1] + 1;
        else 
            pf[i] = pf[i-1];
    }
    ll ans = 0;
    pool(i, n-1, 0){
        if(s[i] == '0' && pf[i] > 0)
            ans += pf[i]+1;
    }
    cout<<ans<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}