//Thu Jul 30 07:51:59 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
const int MOD = 20130427;
struct Node {
    i64 f, g, h;
}dp[100001];
i64 B[100001];
i64 S[100001];
i64 solve(std::vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) dp[i].f = -1;
    auto dfs = [&](auto self, int pos, int lim, int ld) -> Node {
        if (pos == n) return {0, 0, 1};
        if (!lim && !ld && dp[pos].f != -1) return dp[pos];
        Node res = {0, 0, 0};
        int up = lim ? v[pos] : B[1] - 1;
        for (int i = 0; i <= up; i += std::max(1, up)) {
            Node t = self(self, pos + 1, lim && (i == up), ld && (i == 0));
            if (ld && !i) res.f = (res.f + t.f) % MOD;
            else {
                i64 G = (t.g + 1LL * i * S[n - 1 - pos] % MOD * t.h % MOD) % MOD;
                res.f = (res.f + t.f + G) % MOD;
                res.g = (res.g + G) % MOD;
                res.h = (res.h + t.h) % MOD;
            }
        }
        Node t = self(self, pos + 1, 0, 0);
        if (up > 1) {
            i64 G = (1LL * t.g * (up - 1) % MOD + 1LL * (up) * (up - 1) / 2 % MOD * S[n - 1 - pos] % MOD * t.h % MOD) % MOD;
            res.f = (res.f + (t.f * (up - 1) + G)) % MOD; 
            res.g = (res.g + G) % MOD;
            res.h = (res.h + (up - 1) * t.h) % MOD;
        }
        if (!lim && !ld) dp[pos] = res;
        return res;
    };
    auto [f, g, h] = dfs(dfs, 0, 1, 1);
    return f;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> B[1];
    B[0] = 1;
    S[0] = 1;
    int N;
    std::cin >> N;
    std::vector<int> L(N);
    for (int i = 0; i < N; ++i) std::cin >> L[i];
    L[N - 1]--;
    for (int i = N - 1; i >= 0; --i) {
        if (L[i] < 0) {
            if (i > 0) {
                L[i-1]--;
                L[i] += B[1];
            }
            else L[0] = -1;
        }else break;
    }
    int M;
    std::cin >> M;
    std::vector<int> R(M);
    for (int i = 0; i < M; ++i) std::cin >> R[i];
    int K = std::max(N, M);
    for (int i = 1; i <= K; ++i) {
        B[i] = (B[i - 1] * B[1]) % MOD;
        S[i] = (S[i - 1] + B[i]) % MOD;
    }
    i64 ansR = solve(R);
    i64 ansL = L[0] == -1 ? 0 : solve(L);
    std::cout << ((ansR - ansL) % MOD + MOD) % MOD << nl;
}
