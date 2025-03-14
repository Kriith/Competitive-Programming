#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using mint = map<int, int>;
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
    ll n, k, ans{0};
    cin>>n>>k;
    // if(k > log2(n)){
    //     cout<<"0\n";
    //     return;
    // }
    loop(i, (n+1)/2, n+1){
        ll a = i;
        // cout<<a<<sp;
        ll m = n;
        pool(j, k-2, 0){
            ll b = m - a;
            // cout<<b<<sp;
            if(b > a) break;
            if(j == 1){
                // cout<<"in ";
                ans++;
                break;
            }
            m = a;
            a = b;
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