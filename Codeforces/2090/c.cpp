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
    int n; cin>>n;
    int x0 = 1, y0 = 1, x1 = 1, y1 = 2;
    while(n--){
        int t; cin>>t;
        int s1 = x0+y0, s2 = x1 + y1;
        if(x1%3 == 2 && y1%3 == 2) s2 += 2;
        if(t == 0 || (s1 < s2)){
            cout<<x0<<sp<<y0<<nl;
            if(y0 > 1) x0 += 3, y0 -= 3;
            else y0 = x0 + 3, x0 = 1;
        }
        else{
            cout<<x1<<sp<<y1<<nl;
            pi md = {x1%3, y1%3};
            if(md == make_pair(1, 2)){
                if(x1 > 3) x1++, y1 -= 3;
                else x1++, y1--;
            }
            else if(md == make_pair(2, 2)) y1 += 2;
            else if(md == make_pair(2, 1)){
                if(y1 > 2) x1 += 2, y1 -= 2;
                else y1 = x1 + 3, x1 = 1;
            }
        }
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