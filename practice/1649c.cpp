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

int md(int x1, int y1, int x2, int y2){
    return (abs(x1-x2) + abs(y1-y2));
}

void solve(){
    int n, m;
    cin>>n>>m;
    map<int, vi> xp, yp;
    lop(i, n){
        lop(j, m){
            int o;
            cin>>o;
            xp[o].eb(i+1);
            yp[o].eb(j+1);
        }
    }
    dbg(xp, yp);

    auto calc = [&](vi& a) -> ll{
        // a.erase(unique(all(a)), a.end());
        if(a.empty()) return 0;
        sort(all(a));
        dbg(a);
        ll sum = 0;
        ll curr = a[0];
        lopp(i, a.size()){
            sum += 1LL*i*a[i] - curr; 
            curr += a[i];
        }
        return sum;
    };

    ull ans = 0;
    for(auto mp : xp) ans += calc(mp.second);
    for(auto mp : yp) ans += calc(mp.second);
    cout<<ans; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t = 1;
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}