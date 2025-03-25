#include <bits/stdc++.h>

int main() {
    using std::cin; using std::cout;
    int T; cin >> T; 
    while (T--) {
        int N; cin >> N;
        std::array<int, 2> nxt_new{1, 1};
        std::array<int, 2> nxt_old{1, 2};
        for (int z = 0; z < N; z++) { 
            int t; cin >> t;
            if (t == 0 || nxt_new[0] + nxt_new[1] < nxt_old[0] + nxt_old[1]) {
                cout << nxt_new[0] << ' ' << nxt_new[1] << '\n';
                if (nxt_new[1] == 1) {
                    nxt_new[1] = nxt_new[0] + 3;
                    nxt_new[0] = 1;
                } 
                else nxt_new[0] += 3, nxt_new[1] -= 3;
            } 
            else {
                auto [x, y] = nxt_old;
                if (x % 3 == 2 && y % 3 == 1 && y >= 4) { y -= 2; }
                else if (x % 3 == 0 && y % 3 == 0) { x--, y++; }
                cout << x << ' ' << y << '\n';
                if (nxt_old[1] == 1) {
                    nxt_old[1] = nxt_old[0] + 3;
                    nxt_old[0] = 1;
                } 
                else nxt_old[0]++, nxt_old[1]--;
            }
        }
    }
}