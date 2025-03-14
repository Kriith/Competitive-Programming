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
    ll n, mx = 0;
    cin>>n;
    ll a[n];
    lop(i,n) cin>>a[i];
    if(n == 2){
        cout<<min(a[0], a[1])<<nl;
        return;
    }
    ll med = 0, b[3] = {0, 0, 0};
    // cout<<b[2]<<sp;
    loop(i, 2, n){
        // cout<<i<<sp;
        b[0] = a[i-2];
        b[1] = a[i-1];
        b[2] = a[i];
        sort(b, b+3);
        med = b[1];
        // cout<<b[0]<<sp<<b[1]<<sp<<b[2]<<sp;
        if(med > mx) mx = med;
    }
    cout<<mx<<nl;
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