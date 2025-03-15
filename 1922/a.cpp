#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i<b; i++)
void solve(){
    int n;
    string a, b, c;
    cin>>n>>a>>b>>c;
    if(a.compare(c) == 0 || b.compare(c) == 0){
        cout<<"NO\n";
        return;
    }
    FOR(i, 0, n){
        if(a[i] == b[i] && (a[i] != c[i] || b[i] != c[i])){
            cout<<"YES\n";
            return;
        }
        else if(a[i] != b[i] && (a[i] != c[i] && b[i] != c[i])){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}