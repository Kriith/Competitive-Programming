#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sp " "

double rec(vector<vector<vector<double>>>& dp, int x, int y, int z, int n) {
    if(x < 0 || y < 0 || z < 0 || (x == 0 && y == 0 && z == 0)) {
        return 0;
    }
    if(dp[x][y][z] > 0) {
        return dp[x][y][z];
    }
    //dp stores the number of expected operations till all the sushi gets over
    //so E = 1 + prob of plate with 0 * E + prob of plate with 1 * dp(x - 1, y, z) and so on
    //prob of plate with 0 = (n - x - y - z)/n
    //take that to LHS, then eqn simplifies to
    //E = (n + x*dp[x - 1] + y*dp[y-1] ..)/(x + y + z)
    return (dp[x][y][z] = (double(n + x * rec(dp, x - 1, y, z, n) + y * rec(dp, x + 1, y - 1, z, n) + z * rec(dp, x, y + 1, z - 1, n))/double(x + y + z)));
}

void solve(){
    int n;
    cin>>n;
    vector<int> amt(4, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        amt[x]++;
    }
    //3d dp that stores the expected turns to get the pile of {n - (x + y + z), x, y, z} number of plates with i sushis(i.e x plates with 1 sushi) to get to zero
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0.0)));
    cout<<setprecision(10)<<rec(dp, amt[1], amt[2], amt[3], n);
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