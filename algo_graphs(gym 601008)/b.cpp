#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
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

struct dsu {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;
 
    dsu(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }
 
    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
 
    int get_size(int x) {
        return -data[find(x)];
    }
 
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
 
        if (x == y)
            return false;
 
        if (-data[x] < -data[y])
            swap(x, y);
 
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

void solve(){
    int n, m1, m2;
    cin>>n>>m1>>m2;
    vector<array<int, 2>> e(m1);
    dsu d1(n), d2(n);
    lop(i, m1){
        int x, y;
        cin>>x>>y;
        e[i] = {x, y};
        // d1.merge(x, y);
    }
    lop(i, m2){
        int x, y;
        cin>>x>>y;
        // e2[i] = {x, y};
        d2.merge(x, y);
    }
    int ans = 0;
    for(auto &[a, b]: e){
        if(d2.find(a) == d2.find(b)) d1.merge(a, b);
        else ans++;
    }
    // dbg(ans);
    ans += d1.components - d2.components;
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