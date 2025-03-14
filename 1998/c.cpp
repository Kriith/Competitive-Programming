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
    int n, k;
    cin>>n>>k;
    vector<pair<int, bool>> a(n);
    lop(i, n) cin>>a[i].ff;
    lop(i, n) cin>>a[i].ss;
    sort(all(a));
    // dbg(a);

    ll ans = 0;
    pool(i, n-1, -1){
        if(a[i].ss){
            ans += a[i].ff + k;
            if(i < n/2) ans += a[n/2].ff;
            else ans += a[n/2 - 1].ff;
            // dbg(i, a[i].ff, a[n/2].ff, a[n/2 - 1].ff);
            break;
        }
    }
    ans = max(0LL + a[n-1].ff + a[n/2 - 1].ff, ans);

    auto check = [&](int m)->bool{
        int z = 0;
        lop(i, n-1){
            if(!a[i].ss && a[i].ff < m)
                z++;
        }
        dbg(m, z, n/2);
        if(z >= n/2) return false;

        vector<pair<int, bool>> b(a);
        int kk = k;
        pool(i, n-2, -1){
            if(b[i].ss && b[i].ff < m){
                int diff = m - b[i].ff;
                if(diff >= kk){
                    b[i].ff += kk;
                    kk = 0;
                }
                else{
                    b[i].ff = m;
                    kk -= diff;
                }
            }
        }
        sort(all(b));
        dbg(m, b[n/2 - 1].ff, b);
        if(b[n/2 - 1].ff >= m) return true;
        else return false;
    };
    ll l = 1, r = a[n-1].ff + k, t = 0;
    while(l <= r){
        ll m = (r-l)/2 + l;
        if(check(m)){
            t = m;
            l = m + 1;
        }
        else r = m - 1;
        // dbg(l, r, m);
    }
    t += a[n-1].ff;
    dbg(ans, t);
    ans = max(ans, t);
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