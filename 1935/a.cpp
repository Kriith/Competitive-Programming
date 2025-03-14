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
#define pb push_back
#define popb pop_back
#define ff first
#define ss second

void solve(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int l = s.size() - 1;
    if(s[0] < s[l]){
        if(k%2 == 0){
            cout<<s<<"\n";
        }
        else{
            cout<<s;
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
    }
    else if(s[0] > s[l]){
        if(k%2 == 0){
            reverse(s.begin(), s.end());
            cout<<s;
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
        else{
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
    }
    else{
        lopp(i, l){
            if(s[i] < s[l-i]){
                if(k%2 == 0){
            cout<<s<<"\n";
        }
        else{
            cout<<s;
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
                return;
            }
            else if(s[i] > s[l-i]){
                if(k%2 == 0){
            reverse(s.begin(), s.end());
            cout<<s;
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
        else{
            reverse(s.begin(), s.end());
            cout<<s<<"\n";
        }
                return;
            }
        }
        cout<<s<<"\n";
    }
    return;
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