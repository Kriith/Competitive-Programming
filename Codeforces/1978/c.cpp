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
#define pb push_back
#define puf push_front
#define popb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "
#define mie *min_element
#define mxe *max_element

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    ll n, k;
    cin>>n>>k;
    ll mx = (n&1)?((n-1)*(n+1)/2):(n*n/2);
    if(k&1 || k > mx){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vll a(n);
    iota(a.begin(), a.end(), 1);
    ll i = 0, m = n;
    while(k > 2*(m-1)){
        swap(a[i], a[n-i-1]);
        k -= 2*(m-1);
        m -= 2;
        i++;
    }
    k/=2;
    dbg(a, k, i);
    swap(a[i], a[i+k]);
    lop(j, n) cout<<a[j]<<sp;
    cout<<nl;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}