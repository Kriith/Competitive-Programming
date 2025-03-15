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
    ll a[n];
    lop(i, n) cin>>a[i];
    ll pf[n+1];
    pf[0] = 0;
    lopp(i, n+1) pf[i] = pf[i-1] + a[i-1];
    ll count = 0, max[n];
    max[0] = a[0];
    lopp(i, n){
        if(a[i] > max[i-1])
            max[i] = a[i];
        else max[i] = max[i-1];
    }
    lop(i, n){
        if(pf[i+1] == 2*max[i])
            count++;
    }
    cout<<count<<nl;
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