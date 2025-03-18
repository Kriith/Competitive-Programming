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
    int n;
    cin>>n;
    vll a(n);
    lop(i, n) cin>>a[i];

    int xi = n;
    lop(i, n){
        if(a[i] == 1 || a[i] == -1) continue;
        else{ xi = i; break; }
    }
    // dbg(xi);
    set<ll> ans;
    ans.insert(0LL);

    ll s1 = 0, s2 = 0, s = 0, mx1 = a[0], mn1 = a[0], mx2 = a[0], mn2 = a[0];
    lop(i, xi){
        s += a[i];
        ans.insert(s);
        if(a[i] == 1){
            s2 = 0; 
            s1++;
            ans.insert(s1);
        }
        else{
            s1 = 0;
            s2--;
            ans.insert(s2);
        }
        if(i == 0) continue;
        mx1 = max(mx1 + a[i], a[i]);
        mx2 = max(mx1, mx2);
        mn1 = min(mn1 + a[i], a[i]);
        mn2 = min(mn2, mn1);
        ans.insert(mx1); ans.insert(mx2); ans.insert(mn1); ans.insert(mn2);
        dbg(mx1, mx2, mn1, mn2, a[i], i);
    }
    s1 = s2 = s = 0;
    if(xi < n-1) mx1 = mx2 = mn1 = mn2 = a[xi+1]; 
    loop(i, xi + 1, n){
        s += a[i]; 
        ans.insert(s);
        if(a[i] == 1){
            s2 = 0; 
            s1++;
            ans.insert(s1);
        }
        else{
            s1 = 0;
            s2--;
            ans.insert(s2);
        }
        if(i == xi+1) continue;
        mx1 = max(mx1 + a[i], a[i]);
        mx2 = max(mx1, mx2);
        mn1 = min(mn1 + a[i], a[i]);
        mn2 = min(mn2, mn1);
        ans.insert(mx1); ans.insert(mx2); ans.insert(mn1); ans.insert(mn2);
        dbg(mx1, mx2, mn1, mn2, a[i], i);
    }

    if(xi < n && a[xi] != 0){
        ll mxl = 0, mxr = 0, mnr = 0, mnl = 0, s3 = 0, s4 = 0;
        ans.insert(a[xi]);
        pool(i, xi - 1, -1){
            s3 += a[i];
            mxl = max(mxl, s3);
            mnl = min(mnl, s3);
            ans.insert(s3 + a[xi]);
        }
        loop(i, xi+1, n){
            s4 += a[i];
            mxr = max(mxr, s4);
            mnr = min(mnr, s4);
            ans.insert(s4 + a[xi]);
        }
        if(mxl > 0 && mxr > 0)
            for(ll i = 1; i <= mxl + mxr; i++) ans.insert(a[xi] + i);
        if(mnl < 0 && mnr < 0)
            for(ll i = -1; i >= mnl + mnr; i--) ans.insert(a[xi] + i);
    }

    cout<<ans.size()<<nl;
    for(auto i : ans) cout<<i<<sp;
    cout<<nl;
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