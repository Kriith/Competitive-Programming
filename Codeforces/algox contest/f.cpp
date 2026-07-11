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
    lop(i, n)
        cin>>a[i];
    loop(i, 2, n){
        if(a[i]<a[i-1] && a[i-1]>a[i-2]){
            cout<<"YES\n"<<i-1<<" "<<i<<" "<<i+1<<endl;
            return;
        }
    }
    cout<<"NO\n";
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