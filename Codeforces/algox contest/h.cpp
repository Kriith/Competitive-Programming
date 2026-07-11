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
#define pb push_back
#define popb pop_back
#define ff first
#define ss second

void solve(){
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    if(a[0] == 1)
        a[0]++;
    cout<<a[0]<<" ";
    loop(i, 1, n){
        cin>>a[i];
        if(a[i] == 1)
            a[i]++;
        if(a[i]%a[i-1] == 0)
            a[i]++;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}