#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
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
    ll a[n], b[n];
    mll m;
    lop(i, n){
        cin>>a[i];
        m[a[i]] = i;
    }
    lop(i, n){
        cin>>b[i];
    }
    ll ans = 0;
    pool(i, n-1, 0){
        if(m[b[i-1]] > m[b[i]]){
            ans = i;
            break;
        }
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