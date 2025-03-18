#include <bits/stdc++.h>
using namespace std;
 
#define print_arr(arr) for (auto x : arr) cout << x << ' '; cout << endl;
#define pref_arr(pf, a, n) for(int i = 1; i <= n; i++) pf[i] = a[i-1] + pf[i-1];
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) FOR(i, 0, n)
#define FORREV(i, a, b) for(int i = a; i >= b; i--)
#define FORD(i, a, b) for(int i = a; i <= b; i++)
 
#define all(x) x.begin(), x.end()
#define pb push_back
#define popb pop_back
#define ff first
#define ss second
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using mint = map<int, int>;
using mstrint = map<string, int>;
using pi = pair<int, int>;
 
// int bin_srch(const vll &a, int s_idx, int e_idx, int comp){
//     while(s_idx <= e_idx){
//         int m = (s_idx + e_idx) / 2;
//         if(s_idx == e_idx){
//             return m;
//         }
//         if(comp >= a[m]){
//             s_idx = m+1;
//         }
//         else{
//             e_idx = m;
//         }
//     }
//     return -1;
// }
 
void solve(){
    ll n, q;
    cin >> n >> q;
    vll a(n), ques(q), maxm(n+1);
    maxm[0] = 0;
    rep(i, n) {
        cin >> a[i];
        maxm[i+1] = max(maxm[i], a[i]);
    }
    // print_arr(maxm);
    // cout << bin_srch(maxm, 1, n, 6) << endl;
    rep(i, q) cin >> ques[i];
    vll pf(n+1); pref_arr(pf, a, n)
    for(auto &k: ques){
        if(k >= maxm.back()) {
            cout << pf.back() << ' '; 
            continue;
        }
        int idx = upper_bound(all(maxm), k) - maxm.begin();
        cout << pf[idx-1] << ' ';
    }
    cout << endl;
}
 
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}