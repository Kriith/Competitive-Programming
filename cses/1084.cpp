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
    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n], b[n];
    lop(i, n) cin>>a[i];
    lop(i, m) cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    ll i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            i++;
            j++;
            ans++;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    cout<<ans<<nl;
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