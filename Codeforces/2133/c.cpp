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
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    lopp(i, n+1){
        cout<<"? "<<i<<sp<<n<<sp;
        lopp(i, n+1) cout<<i<<sp;
        cout<<nl;
        cout.flush();
        int x;
        cin>>x;
        pq.push({x, i});
    }
    // while(!pq.empty()){
    //     cout<<pq.top().ff<<sp<<pq.top().ss<<endl;
    //     pq.pop();
    // }
    int k = pq.top().first;
    vector<int> ans;
    while(1){
        auto t = pq.top();
        // cout<<t.first<<sp<<t.second<<nl;
        // cout.flush();
        pq.pop();
        vi check;
        while(!pq.empty() && pq.top().first == t.first){
            check.push_back(pq.top().second);
            pq.pop();
        }
        if(ans.empty() || check.empty()) ans.push_back(t.second);
        else{
            check.push_back(t.second);
            int prev = *ans.rbegin();
            for(auto i: check){
                cout<<"? "<<prev<<" 2 "<<prev<<sp<<i<<nl;
                cout.flush();
                int x;
                cin>>x;
                if(x > 1){
                    ans.push_back(i);
                    // cout<<i<<nl;
                    // cout.flush();
                    break;
                }
            }
        }
        // cout<<ans.size()<<nl;
        // cout.flush();
        if(ans.size() == k || t.first == 0) break;
    }
    cout<<"! "<<k<<sp;
    lop(i, k) cout<<ans[i]<<sp;
    cout<<nl;
    cout.flush();
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