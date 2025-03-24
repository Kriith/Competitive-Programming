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
    vector<vector<char>> a(n, vector<char>(m));
    lop(i, n) lop(j, m) cin>>a[i][j];
    // dbg(a);
    // cout<<a[n-1][m-1];

    lopp(i, n){
        lopp(j, m){
            //no ones left or top of an one
            if(a[i][j] == '1' && a[i-1][j] == '0' && a[i][j-1] == '0'){ 
                cout<<"NO\n"; 
                return; 
            }
        }
    }
    // lopp(i, n){
    //     if(a[i][0] == '1') continue;
    //     lopp(j, m){
    //         if(a[i][j] == '1' && a[i-1][j] == '0'){
    //             cout<<"NO\n";
    //             return;
    //         }
    //     }
    // }
    // lopp(j, m){
    //     if(a[0][j] == '1') continue;
    //     lopp(i, n){
    //         if(a[i][j] == '1' && a[i][j-1] == '0'){
    //             cout<<"NO\n";
    //             return;
    //         }
    //     }
    // }
    lopp(i, n){
        bool flg = 0;
        lop(j, m){
            if(a[i][j] == '0') flg = 1;
            if(flg && a[i][j] == '1' && a[i-1][j] == '0'){
                cout<<"NO\n";
                return;
            }
        }
    }
    lopp(j, m){
        bool flg = 0;
        lop(i, n){
            if(a[i][j] == '0') flg = 1;
            if(flg && a[i][j] == '1' && a[i][j-1] == '0'){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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