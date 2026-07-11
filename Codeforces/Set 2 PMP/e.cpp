#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using mint = map<int, int>;
using mll = map<ll, ll>;
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
#define mie *min_element
#define mxe *max_element

void solve(){
    vector<string> v = {"1869", "1968", "1689", "6198", "1698", "1986", "1896"};
    string n;
    cin>>n;
    string s = "";
    map<char, bool> m;
    m['1'] = m['6'] = m['8'] = m['9'] = 1;
    ll k = n.size(), r = 0, c0 = 0;
    lop(i, k){
        if((n[i] == '1' || n[i] == '6' || n[i] == '8' || n[i] == '9') && m[n[i]]) 
            m[n[i]] = 0;
        else if(n[i] == '0') c0++;
        else{ 
            r = (r*10 + (n[i]-'0'))%7;
            s.push_back(n[i]);
        }
    }
    r = (r*10000)%7;
    r = (r)?(7-r):0;
    cout<<s<<v[r];
    lop(i, c0) cout<<'0';
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