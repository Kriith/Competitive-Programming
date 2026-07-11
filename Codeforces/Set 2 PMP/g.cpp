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

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

void solve(){
    ll n;
    string s;
    cin>>n>>s;
    ll s1 = 0, s0 = 0;
    lop(i, n){
        if(s[i] == '1') s1++;
        else s0++;
    }
    if((s1&1) || (s[0] == '0') || (s[n-1] == '0')){
        cout<<"NO\n";
        return;
    } 
    cout<<"YES\n";
    string a = "", b = "";
    ll t1 = 0, t0 = 1;
    lop(i, n){
        if(s[i] == '1'){
            t1++;
            if(t1 <= s1/2){
                a.pb('(');
                b.pb('(');
            }
            else{
                a.pb(')');
                b.pb(')');
            }
        }
        else{
            if(t0){
                a.pb('(');
                b.pb(')');
                t0 = 0;
            }
            else{
                a.pb(')');
                b.pb('(');
                t0 = 1;
            }
        }
    }
    cout<<a<<nl<<b<<nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}