#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using mint = map<int, int>;
using pi = pair<int, int>;

#define loop(i, a, b) for(int i = a; i<b; i++)
#define pool(i, a, b) for(int i = a; i>b; i--)
#define lop(i, n) for(int i = 0; i<n; i++)
#define lopp(i, n) for(int i = 1; i<n; i++)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define popf pop_front
#define ff first
#define ss second
#define nl "\n"
#define sp " "

void solve(){
    int n, k, flag = 0;
    cin>>n>>k;
    int a[n+1];
    a[0] = 0;
    mint m;
    lopp(i,n+1){
        cin>>a[i];
        if(i == k){
            m[a[i]] = 1;
        }
        if(i>k){
            if(a[i] != a[k])
                flag = 1;
            else m[a[k]] ++;
        }
    }
    if(flag){
        cout<<"-1";
        return;
    }
    int i = k-1, moves = k-1;
    while(a[i] == a[k]){
        // cout<<a[i]<<sp<<i<<sp;
        // cout<<"in";
        i--;
        moves--;
    }
    cout<<moves;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}