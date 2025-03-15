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
    int n, m; string s;
    cin>>n>>m>>s;
    vvll a(n, vll(m));
    lop(i, n){
        lop(j, m) cin>>a[i][j];
    }

    vvll b(a);
    // lop(i, n){ lop(j, m) cout<<b[i][j]<<sp; cout<<nl; }
    vector<vector<bool>> c(n, vector<bool>(m, 0));
    int t = n + m - 1;
    c[0][0] = c[n-1][m-1] = 1;
    int k = 0, l = 0;
    lop(i, t-1){
        if(s[i] == 'D')c[++k][l] = 1;
        else c[k][++l] = 1;
    }
    lop(i, n){
        int cnt = 0, index = -1; ll sum = 0;
        lop(j, m){
            if(c[i][j]){
                cnt++;
                if(cnt > 1) break;
                index = j;
            }
            sum += b[i][j];
        }
        if(cnt == 1){
            // lop(j, m) sum += b[i][j];
            b[i][index] = (-1LL)*sum;
            c[i][index] = 0;
        }
    }
    // lop(i, n){ lop(j, m) cout<<b[i][j]<<sp; cout<<nl; }
    lop(i, m){
        int cnt = 0, index = -1; ll sum = 0;
        lop(j, n){
            if(c[j][i]){
                cnt++;
                if(cnt > 1) break;
                index = j;
            }
            sum += b[j][i];
        }
        if(cnt == 1){
            // lop(tt, n) sum += b[tt][i];
            b[index][i] = (-1LL)*sum;
            c[index][i] = 0;
        }
    }
    // lop(i, n){ lop(j, m) cout<<b[i][j]<<sp; cout<<nl; }
    lop(i, n){
        lop(j, m){
            if(c[i][j]){
                bool flg = 0; ll sum = 0;
                lop(tt, n){
                    if(tt != i){
                        if(c[tt][j]){ flg = 1; break; }
                        else sum += b[tt][j];
                    }
                }
                if(flg){
                    sum = 0;
                    lop(tt, m) sum += b[i][tt];
                }
                b[i][j] = (-1LL)*sum;
                c[i][j] = 0;
            }
        }
    }
    lop(i, n){
        lop(j, m) cout<<b[i][j]<<sp;
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