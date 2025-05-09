#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
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
    int n;
    cin>>n;
    set<vll> s1, s2;
    s1.insert({2, 1, 1});
    while(n--){
        dbg(s1, s2);
        int q; cin>>q;
        int x, y;
        if(q && s2.size() && ((*s2.begin())[0] < (*s1.begin())[0])){
            x = (*s2.begin())[1], y = (*s2.begin())[2];
            s2.erase(s2.begin());
        }
        else{
            x = (*s1.begin())[1], y = (*s1.begin())[2];
            s1.erase(s1.begin());
            s1.insert({{x+y+3, x+3, y}, {x+y+3, x, y+3}});
            s2.insert({{x+y+1, x+1, y}, {x+y+1, x, y+1}, {x+y+4, x+1, y+1}});
        }
        cout<<x<<sp<<y<<nl;
    }
    return;
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