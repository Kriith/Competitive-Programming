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

unordered_map<char, int> br = {{'(', -1}, {')', 1}};

void solve(){
    int n; string s;
    cin>>n>>s;
    if(n&1){cout<<"-1\n"; return;}
    stack<char> reg, rev;
    vi rg, rv;
    lop(i, n){
        if(br[s[i]] < 0){
            if(!rev.empty()){rev.pop(); rv.pb(i);}
            else{reg.push(s[i]); rg.pb(i);}
        }
        else{
            if(!reg.empty()){reg.pop(); rg.pb(i);}
            else{rev.push(s[i]); rv.pb(i);}
        }
    }
    if((!rev.empty()) || (!reg.empty())){cout<<"-1\n"; return;}
    if(rg.empty() || rv.empty()){
        cout<<"1\n";
        lop(i, n) cout<<"1 ";
        cout<<nl;
        return;
    }
    cout<<"2"<<nl;
    vi ans(n, 1);
    lop(i, rv.size()) ans[rv[i]] = 2;
    lop(i, n) cout<<ans[i]<<sp;
    cout<<nl;
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