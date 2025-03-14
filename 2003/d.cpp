#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

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
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    int n, m;
    cin>>n>>m;
    vvi a(n);
    vi l(n);
    lop(i, n){
        cin>>l[i];
        lop(j, l[i]){
            int x; cin>>x;
            a[i].pb(x);
        }
        sort(all(a[i]));
    }
    int mex = 0;

    lop(i, n){
        vector<bool> b(l[i] + 2, 1);

        lop(j, l[i]){
            if(a[i][j] < l[i] + 2)
                b[a[i][j]] = 0;
        }

        bool flg = 1;
        lop(j, l[i] + 2){
            if(b[j]){
                dbg(a[i], j, mex);
                if(flg) flg = 0; 
                else{ 
                    mex = max(mex, j);
                    break;
                }
            }
        }
        dbg(mex);
    }

    ll ans = 0;
    // dbg(ans);
    if(m > mex) 
        ans += 1LL*m*(m+1)/2 + 1LL*mex*(mex+1)/2;
    else
        ans += 1LL*mex*(m+1);
    cout<<ans<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ll t = 1;
    cin>>t; 
    while(t--)
        solve();
    return 0;
}