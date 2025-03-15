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
    int n;
    cin>>n;
    // cout<<n<<nl;
    vll a(n), b(n);
    lop(i, n) cin>>a[i];
    ll diff = 0;
    lop(i, n){
        cin>>b[i];
        if(a[i] > b[i])
            diff++;
    }
    if(diff == 0){
        cout<<"0\n";
        return;
    }
    ll count = 0;
    // cout<<b[n-1]<<nl;
    while(diff > 0){
        diff = 0;
        auto x = a.emplace(a.begin(), 1);
        a.pb();
        count++;
        lop(i, n){
            if(a[i] > b[i])
                diff++;
        }
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