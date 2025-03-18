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

bool check(ll a[], ll c[], ll h, ll n, ll m){
    unsigned sum = 0;
    lop(i, n) sum += ((m-1)/c[i] +1)*a[i];
    return sum>=h;
}

void solve(){
    ll h, n;
    cin>>h>>n;
    ll a[n], c[n];
    lop(i, n) cin>>a[i];
    lop(i, n) cin>>c[i];
    ll l = 1, r = 1e12, ans = 0;
    while(l<=r){
        ll m = l + (r-l)/2;
        if(check(a, c, h, n, m)){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    cout<<ans<<nl;
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