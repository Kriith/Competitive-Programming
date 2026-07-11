#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define puf push_front
#define popb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "
#define mie *min_element
#define mxe *max_element
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    vll h(n);
    lop(i, n) cin>>h[i];
    vll x(n);
    lop(i, n) cin>>x[i];

    auto check = [&](ll q) -> bool{
        mll mp;
        lop(i, n){
            ll t = m - (ll)ceil(h[i]*1.0/q);
            if(t < 0) continue;
            mp[max(x[i] - t, 0LL)]++;
            mp[x[i] + t + 1]--;
            // dbg(m, t, h[i], q, ceil(h[i]/q), x[i], x[i] - t, x[i] + t + 1);
        }
        // dbg(q, mp);
        ll sum = 0;
        for(auto& i : mp){
            sum += i.second;
            if(sum >= k) return true;
        }
        return false;
    };

    ll l = 0, r = 1e15, ans = -1;
    while(l <= r){
        ll mid = (r-l)/2 + l;
        if(check(mid)){ r = mid - 1; ans = mid; }
        else l = mid + 1;
    }
    cout<<ans<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t = 1;
    cin>>t; 
    while(t--)
        solve();
    return 0;
}