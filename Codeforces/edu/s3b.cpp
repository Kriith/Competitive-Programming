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
    int n, k;
    cin>>n>>k;
    int a[n];
    lop(i, n) cin>>a[i];
    // int pf[n];
    // pf[0] = a[0];
    // lopp(i, n) pf[i] = pf[i-1] + a[i];

    auto check = [&](int m)->bool{
        int runsum = 0, j = k;
        lop(i, n){
            if(runsum + a[i] <= m){
                runsum += a[i];
                // runcnt++;
            }
            else{
                if(a[i] > m) return false;
                else{
                    j--;
                    // runcnt = 0;
                    runsum = a[i];
                }
            }
        } 
        if(runsum <= m)
            j--;    
        else return false;
        if(j >= 0) return true;
        else return false;
    };
    int l = 1, r = accumulate(a, a+n, 0), ans = r;
    while(l <= r){
        int m = (r-l)/2 + l;
        // dbg(m, l, r);
        if(check(m)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
        dbg(m, l, r);b
    }
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
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}