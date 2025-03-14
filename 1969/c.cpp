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
    ll n, k;
    cin>>n>>k;
    ll a[n], sum = 0;
    cin>>a[0];
    vll d(n);
    mll diff;
    lopp(i, n){
        cin>>a[i];
        d[i] = abs(a[i] - a[i-1]);
        diff[d[i]] = i;
        sum += a[i];
    }
    sort(d.begin(), d.end(), greater<ll>());
    lopp(i, k){
        ll t = diff[d[i]];
        ll x = a[t];
        ll y = a[t - 1];
        sum -= d[i];
        if(x < y){
            if(i > 0 && abs(a[t+1] - a[t-1]) > d[k-1]){
                d.pb();
                d.insert(d.begin() + k-1, abs(a[t-2] - a[t]));
                sort(d.begin()+i+1, d.end(), greater<ll>());
            }
        }
        else{
            if((i < n-1) && abs(a[t-2] - a[t]) > d[k-1]){
                d.pb();
                d.insert(d.begin() + k-1, abs(a[t+1] - a[t-1]));
                sort(d.begin()+i+1, d.end(), greater<ll>());
            }
        }
    }
    cout<<sum<<nl;
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