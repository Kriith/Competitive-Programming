#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
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
    int n, m;
    cin>>n;
    int r[n];
    lop(i, n) cin>>r[i];
    cin>>m;
    int b[m];
    lop(i, m) cin>>b[i];
    ll rs[n+1], bs[m+1];
    rs[0] = bs[0] = 0;
    ll rm = 0, bm = 0;
    lop(i, n){
        rs[i+1] = rs[i] + r[i];
        if(rs[i+1] >= rm) rm = rs[i+1];
    }
    lop(i, m){
        bs[i+1] = bs[i] + b[i];
        if(bs[i+1] >= bm) bm = bs[i+1];
    }
    cout<<(rm+bm)<<nl;
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