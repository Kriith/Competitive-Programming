#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define popb pop_back
#define ff first
#define ss second

const char nl = '\n';
const char sp = ' ';
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using msll = map<string, ll>;
using pll = pair<ll, ll>;

#ifndef ONLINE_JUDGE
#include "C:/Users/HP/Desktop/Competitive Programming/debug.h"
#else
#define dbg(...) 42
#endif

#define pref_arr(pf, a, n) for(int i = 1; i <= n; i++) pf[i] = a[i-1] + pf[i-1];
#define rep(i, n) for(int i = 0; i < n; i++)
#define forr(i, a, b) for(int i = a; i >= b; i--)
#define ford(i, a, b) for(int i = a; i <= b; i++)
#define trav(x, itr) for(auto &x : itr)
#define readv(A) for(auto &i: A) cin >> i;
#define mkuni(x) (x.resize(unique(all(x)) - x.begin()))
#define sz(x) (ll)x.size()

template <typename T>
vector<ll> sort_indexes(const vector<T> &v){
    vector<ll> idx(v.size());
    iota(all(idx), 0);
    stable_sort(all(idx), [&v](ll i1, ll i2) {return v[i1] < v[i2];});
    return idx;
}

template<class T> bool ckmin(T&a, T b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T b) { bool B = a < b; a = max(a,b); return B; }

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
    if (check_ok) assert(check(ok));
    while (abs(ok - ng) > 1) {
        auto x = (ng + ok) / 2;
        (check(x) ? ok : ng) = x;
    }
    return ok;
}

void solve(){
    ll N, M;
    cin >> N >> M;
    vll A(N, 1), B(N);
    ford(i, 1, N-1) cin >> A[i]; 
    readv(B);
    sort(all(A));
    sort(all(B));
    dbg(A);
    dbg(B);
    auto check = [&](ll k){
        bool ans{1};
        ford(i, 0, N-k-1){
            if(A[i] >= B[i+k]){
                ans = 0; break;
            }
        }
        // dbg(k, ans);
        return ans;
    };
    ll ans = binary_search(check, N, -1);
    cout << ans << nl;
}

bool test_cases = 1;

int main(){
#ifndef ONLINE_JUDGE
    freopen("C:/Users/HP/Desktop/Competitive Programming/input.txt", "r", stdin);
    freopen("C:/Users/HP/Desktop/Competitive Programming/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    if(test_cases) cin >> T;
    rep(t, T){
        cerr << "------ " << t + 1 << " ------\n";
        solve();
    }
    return 0;
}