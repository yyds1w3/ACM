//2026-04-10 16:25:28
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

void solve() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        if (H[i] <= H[i + 1] && H[i + 1] - H[i] > 1) {
            std::cout << "Lose" << nl;
            return;
        }else if (H[i] > H[i + 1] && H[i] - H[i + 1] > X) {
            std::cout << "Lose" << nl;
            return;
        }
    }
    std::cout << "Win" << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
