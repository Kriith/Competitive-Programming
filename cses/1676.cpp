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

struct dsu{
    int t, sz;
    vi p, rank;

    dsu(int n){
        t = n;
        p.resize(t + 1, 0);
        lopp(i, t + 1) p[i] = i;
        rank.resize(t + 1, 1);
        sz = 1;
    }

    int find(int x){
        // dbg(p);
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int x, int y){
        // dbg(x, y);
        // x = find(x);
        // y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y])
            p[y] = x, rank[x] += rank[y];
        else p[x] = y, rank[y] += rank[x];
        // dbg(x, y, rank[x], rank[y], sz);
        sz = max(max(rank[x], rank[y]), sz);
    }
};

void solve(){
    int n, m;
    cin>>n>>m;
    vi a(m), b(m);
    lop(i, m) cin>>a[i]>>b[i];

    dsu ds(n);
    int components = n;
    lop(i, m){
        int x = ds.find(a[i]), y = ds.find(b[i]);
        if(x != y){
            // dbg(a[i], b[i], x, y);
            components--;
            ds.merge(x, y);
        }
        cout<<components<<sp<<ds.sz<<nl;
    }
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