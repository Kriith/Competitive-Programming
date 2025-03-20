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

struct skill{
    bool operator()(vi p1, vi p2){
        return p1[0] > p2[0];
    }
};

struct price{
    bool operator()(vi p1, vi p2){
        return p1[1] > p2[1];
    }
};

struct cmp{
    bool operator()(pi p1, pi p2){
        return p1.ff > p2.ff;
    }
};

void solve(){
    int n, m, s;
    cin>>n>>m>>s;
    vi a(m), b(n), c(n);
    lop(i, m) cin>>a[i];
    lop(i, n) cin>>b[i];
    lop(i, n) cin>>c[i];

    vector<pair<int, int>> bugs(m); //stores bugs and their original index
    lop(i, m) bugs[i] = {a[i], i};
    sort(all(bugs), cmp());         //sorting by complexity decreasing
    vvi std(n, vi(3));              //stores students skill, price and original index
    lop(i, n) std[i] = {b[i], c[i], i + 1};
    sort(all(std), skill());        //sorting by students' skill decreasing
    // dbg(std, bugs);

    vi ans;
    auto check = [&](int t)->bool{
        vi currans(m);
        ll cost = 0;
        int ind = 0, i = 0;
        priority_queue<vi, vvi, price> pq;  //min heap pq sorting by students' price
        while(ind < m){
            for(;i < n; i++){               //loop which adds students to pq if they can solve the problem bugs[ind]
                if(std[i][0] < bugs[ind].ff) break;
                pq.push(std[i]);
            }
            if(pq.empty()) return false;
            loop(j, ind, min(ind + t, m)) currans[bugs[j].ss] = pq.top()[2]; 
            // dbg(currans, pq.top(), ind, t);
            cost += pq.top()[1], ind += t;  //if student can solve bugs[ind], it can solve next t problems too 
            pq.pop();
        }
        if(cost <= s) ans = currans;
        return cost <= s;
    };

    int l = 1, r = m;
    while(l <= r){
        int t = (r - l)/2 + l;
        if(check(t)) r = t - 1;
        else l = t + 1;
    }
    if(ans.empty()) cout<<"NO\n";
    else{
        cout<<"YES\n";
        lop(i, (int)ans.size()) cout<<ans[i]<<sp;
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
    // cin>>t; 
    while(t--)
        solve();
    return 0;
}