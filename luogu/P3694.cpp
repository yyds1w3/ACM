//Tue Aug  4 08:48:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    std::vector<int> a(n);
    std::vector<int> cnt(m);
    std::vector<std::vector<int>> pref(m, std::vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref[i][j] = pref[i][j - 1] + (a[j - 1] == i ? 1 : 0);
        }
    }

    std::vector<int> len(1<<m, 0);
    for (int i = 0; i < (1<<m); ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                len[i] += cnt[j];
            }
        }
    }

    std::vector<int> dp(1<<m, INF);
    dp[0] = 0;
    
    for (int i = 0; i < (1 << m); ++i) {
        if (dp[i] == INF) continue;

        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) continue;
            int start_idx = len[i];
            int end_idx = len[i] + cnt[j];
            int already_in_place = pref[j][end_idx] - pref[j][start_idx];
            int tmp = cnt[j] - already_in_place;
            dp[i | (1<<j)] = std::min(dp[i | (1<<j)], dp[i] + tmp);
        }
    }
    
    std::cout << dp[(1<<m)-1] << nl;
    return 0;
}
