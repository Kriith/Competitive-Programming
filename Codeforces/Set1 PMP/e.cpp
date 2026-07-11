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
    ll n;
    cin>>n;
    ll v[n], u[n];
    lop(i, n){ 
        cin>>v[i];
        u[i] = v[i];
    }
    sort(u, u+n);
    ll vs[n+1], us[n+1];
    vs[0] = us[0] = 0;
    lop(i, n){
        vs[i+1] = vs[i] + v[i];
        us[i+1] = us[i] + u[i];
    }
    ll m;
    cin>>m;
    while(m--){
        ll t, l ,r;
        cin>>t>>l>>r;
        l--;
        if(t == 1) cout<<(vs[r] - vs[l])<<nl;
        else cout<<(us[r] - us[l])<<nl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}