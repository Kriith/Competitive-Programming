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

int solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vvc s(n+1, vc(m+1, '#'));
    lopp(i, n+1) lopp(j, m+1) cin>>s[i][j];

    vvi pf(n+1, vi(m+1, 0));
    lopp(i, n+1) lopp(j, m+1) pf[i][j] += pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + (int)(s[i][j] == 'g');
    dbg(pf);
    auto calc = [&](int i, int j)->int{
        int ip = min(n, i + k - 1), jp = min(m, j + k - 1), im = max(i - k, 0), jm = max(j - k, 0);
        return (pf[ip][jp] + pf[im][jm] - pf[ip][jm] - pf[im][jp]);
    };

    int ans = pf[n][m];
    lopp(i, n+1) lopp(j, m+1) if(s[i][j] == '.') ans = min(ans, calc(i, j));
    return (pf[n][m] - ans);
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
        cout<<solve()<<nl;
    return 0;
}