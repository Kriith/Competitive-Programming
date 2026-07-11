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

ll k;

ll solve(ll t, ll v, ll sum){
    if(v/t == 0) return sum;
    sum += v/t;
    // cout<<sum<<sp<<t<<nl;
    return solve(t*k, v, sum);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n>>k;
    ll l = 1, r = n, ans = 0;
    while(r >= l){
        ll mid = l + (r-l)/2;
        // cout<<solve(k, mid, 0)<<" main \n";
        ll sum = 0;
        sum = mid + solve(k, mid, sum);
        // cout<<nl<<mid<<sp<<sum<<nl;
        if(sum >= n){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<nl;
    return 0;
}