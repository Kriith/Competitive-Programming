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
    ll n;
    cin>>n;
    vll b(n+2);
    lop(i, n+2) cin>>b[i];
    // auto it = b.end();
    // cout<<*it<<nl;
    sort(b.begin(), b.end());
    ll pf[n+3];
    pf[0] = 0;
    lop(i, n+2) pf[i+1] = pf[i] + b[i];
    ll diff = pf[n+1] - b[n+1];
    auto it = find(b.begin(), b.end(), diff);
    if(it == b.end() || it == b.end()-1){
        if(pf[n] == b[n]){
            b.erase(b.end()-2, b.end()-1);
        }
        else{
            cout<<"-1\n";
            return;
        }
    }
    else{
            // cout<<"in ";
        b.erase(it);
        b.erase(b.end()-1);
    }
    lop(i, n) cout<<b[i]<<sp;
    cout<<nl;
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