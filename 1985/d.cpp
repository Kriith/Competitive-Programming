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
    ll n, m, cnt = 0;
    pi p = {-1, -1};
    cin>>n>>m;
    char c[n][m];
    lop(i, n){
        ll cn = 0;
        lop(j, m){
            cin>>c[i][j];
            if(c[i][j] == '#'){
                cn++;
                if(cn == 1 && p.ff == -1) p = make_pair(i+1, j+1);
            }
        }
        if(cn > 0) cnt++;
    }
    // cout<<cnt<<sp;
    if(cnt == 1) cout<<p.ff<<sp<<p.ss<<nl;
    else cout<<(p.ff+cnt/2)<<sp<<p.ss<<nl;
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