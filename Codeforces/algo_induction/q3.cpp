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
#define pb push_back
#define popb pop_back
#define ff first
#define ss second
#define nl "\n"

void solve(){
    int n;
    cin>>n;
    vector<vector<long long>> a;
    // vll a[n];
    int min = 0;
    lop(i, n){
        int m;
        cin>>m;
        vll b;
        a.pb(b);
        lop(j, m){
            ll x;
            cin>>x;
            // cout<<x<<nl;
            a[i].pb(x);
            // cout<<a[i][j]<<" ";
        }
        // cout<<nl;
        sort(a[i].begin(), a[i].end());
        if(i == 0) continue;
        if((a[i][0] < a[min][0]) || a[i][0] < a[i][1])
           min = i;
        else if(a[i][0] == a[min][0]){
            // cout<<"1\n";
            if(a[i][1] < a[min][1]){
                // cout<<"2\n";
                min = i;
            }
        }
    }
    // cout<<min<<nl;
    int ans = 0;
    lop(i, n){
        if(i != min) ans+= a[i][1];
        else ans += a[i][0];
        // cout<<a[i][0]<<" "<<a[i][1]<<nl;
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