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
    ll x, y, z, k;
    cin>>x>>y>>z>>k;
    ll l, w, d, mx;
    l = w = d = mx = 0;
    lopp(i, x+1){
        if(k%i != 0) continue;
        lopp(j, y+1){
            if((k/i)%j != 0) continue;
            ll m = (k/i)/j;
            ll n = (x-i+1)*(y-j+1)*(z-m+1);
            mx = (n>mx)?n:mx;
        }
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