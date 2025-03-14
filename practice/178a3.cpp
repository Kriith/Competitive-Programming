#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vll = vector<long long>;
using vvi = vector<vector<ll>>;
using mint = map<ll, ll>;
using pi = pair<ll, ll>;

#define loop(i, a, b) for(ll i = a; i<b; i++)
#define pool(i, a, b) for(ll i = a; i>b; i--)
#define lop(i, n) for(ll i = 0; i<n; i++)
#define lopp(i, n) for(ll i = 1; i<n; i++)
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
    ll a[n+1];
    a[0] = 0;
    lopp(i, n+1){
        cin>>a[i];
    }
    vll v(n+1);
    v[0] = 0;
    v[n] = 0;
    lopp(i, n){
        v[i] += a[i];
        ll t = i+pow(2, (ll)log2(n-i));
        v[t] += v[i];
        // cout<<i<<sp<<t<<sp<<v[i]<<sp<<v[t]<<nl;
    }
    lopp(i, n){ 
        v[i] += v[i-1];
        cout<<v[i]<<nl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // ll t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}