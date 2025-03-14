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

const string g = "Ashishgup", f = "FastestFinger";
// map<int, int> hp;

// void sieve(int N){
//     // const int N = 1e9;
//     hp[0] = hp[0] = 0;
//     for(int i = 2; i <= N; i++){
//         if(!hp.contains(i)){
//             hp[i] = i;
//             for(int j = 2*i; j < N; j += i){
//                 hp[j] = i;
//                 // if(!lp.contains(j)) lp[j] = i;
//                 // dbg(j, i, hp[j], lp[j]);
//             }
//         }
//     }
// }

bool isPrime(int n){
    bool flg = 1;
    loop(i, 2, sqrt(n) + 1){
        if(n%i == 0){ flg = 0; break; }
    }
    dbg(n, flg);
    return flg;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    lop(i, n) cin>>a[i];
    // sieve(mxe(all(a)) + 1);

    lop(i, n){
        if(a[i] == 1) cout<<f<<nl; 
        else if(a[i] == 2 || a[i]&1) cout<<g<<nl;
        else{
            if(!(a[i]&(a[i] - 1))) cout<<f<<nl;
            else{
                if(a[i]%4 == 0) cout<<g<<nl;
                else if(isPrime(a[i]/2)) cout<<f<<nl;
                else cout<<g<<nl;
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
    // sieve();
    ll t = 1;
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}