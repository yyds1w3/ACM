//2026-04-10 16:54:51
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int> C(N - 1), A(N);
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> C[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
}
