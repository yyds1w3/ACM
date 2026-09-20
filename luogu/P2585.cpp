//Sat Aug  8 07:02:26 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp1[500001][3];
int dp2[500001][3];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    int idx = 0;
    auto dfs = [&](auto self) -> void {
        if (idx >= n) return;
        if (s[idx] == '0') {
            dp1[idx][0] = dp2[idx][0] = 1;
            dp1[idx][1] = dp2[idx][1] = 0;
            dp1[idx][2] = dp2[idx][2] = 0;
            idx++;
            return;
        }
        if (s[idx] == '1') {
            int u = idx;
            int v = idx + 1;
            idx++;
            self(self);
            dp1[u][0] = std::max(dp1[v][1], dp1[v][2]) + 1;
            dp1[u][1] = std::max(dp1[v][0], dp1[v][2]);
            dp1[u][2] = std::max(dp1[v][0], dp1[v][1]);
            dp2[u][0] = std::min(dp2[v][1], dp2[v][2]) + 1;
            dp2[u][1] = std::min(dp2[v][0], dp2[v][2]);
            dp2[u][2] = std::min(dp2[v][0], dp2[v][1]);
            return;
        }
        if (s[idx] == '2') {
            int u = idx;
            int v1 = idx + 1;
            idx++;
            self(self);
            int v2 = idx;
            self(self);
            dp1[u][0] = std::max(dp1[v1][1] + dp1[v2][2], dp1[v1][2] + dp1[v2][1]) + 1;
            dp1[u][1] = std::max(dp1[v1][0] + dp1[v2][2], dp1[v1][2] + dp1[v2][0]);
            dp1[u][2] = std::max(dp1[v1][0] + dp1[v2][1], dp1[v1][1] + dp1[v2][0]);
            dp2[u][0] = std::min(dp2[v1][1] + dp2[v2][2], dp2[v1][2] + dp2[v2][1]) + 1;
            dp2[u][1] = std::min(dp2[v1][0] + dp2[v2][2], dp2[v1][2] + dp2[v2][0]);
            dp2[u][2] = std::min(dp2[v1][0] + dp2[v2][1], dp2[v1][1] + dp2[v2][0]);
            return;
        }
    };
    dfs(dfs);
    std::cout << std::max({dp1[0][0], dp1[0][1], dp1[0][2]}) << " "
              << std::min({dp2[0][0], dp2[0][1], dp2[0][2]}) << nl;
}
