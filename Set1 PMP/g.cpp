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
#define mie *min_element
#define mxe *max_element

void solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n], b[m], am = 0, bm = 0;
    lop(i, n) cin>>a[i];
    lop(i, m) cin>>b[i];
    lop(i, n) am = (a[i] < a[am])?i:am;
    lop(i, m) bm = (b[i] > b[bm])?i:bm;
    // cout<<am<<sp<<bm<<sp;
    if(b[bm] > a[am]) swap(a[am], b[bm]);
    if(!(k&1)){
        lop(i, n) am = (a[i] > a[am])?i:am;
        lop(i, m) bm = (b[i] < b[bm])?i:bm;
        if(a[am] > b[bm]) swap(a[am], b[bm]);
        // cout<<"in ";
    }
    // cout<<am<<sp<<bm<<sp;
    ll ans = 0;
    lop(i, n) ans += a[i];
    cout<<ans<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}