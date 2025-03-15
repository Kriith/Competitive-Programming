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

// set<int> trp = {101,401,1601,2705,3601,4625,6401,10001,10817,13457,14401,18497,19601,21905,24337,25601,26897,32401,40001,40001,41617,43265,44945,48401,53825,57601,59537,67601,67601,67601,67601,73985,78401,85265,87617,90001,90001,97345,102401,107585,115601,115601,115601,115601,121105,126737,129601,132497,144401,150545,160001,160001,163217,166465,173057,176401,179777,190097,193601,197137};

void solve(){
    int n;
    cin>>n;
    if(!(n&1)){
        lopp(i, n/2+1) cout<<i<<sp<<i<<sp;
        cout<<nl;
    }
    else if(n < 27) cout<<-1<<nl;
    else{
        cout<<1<<sp;
        loop(i, 2, 6) cout<<i<<sp<<i<<sp;
        cout<<1<<sp;
        loop(i, 6, 12) cout<<i<<sp<<i<<sp;
        cout<<"12 13 13 1 12 ";
        loop(i, 14, n/2+1) cout<<i<<sp<<i<<sp;
        cout<<nl;
    }
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