#include <bits/stdc++.h>
#include <vector>
using ll = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, M;
    std::cin >> N >> M;
    std::vector<int> C(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> C[i];
    }
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i] >> B[i];
        A[i]--;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (C[A[i]] >= 0) {
            int d = std::min(C[A[i]], B[i]);
            ans += d;
            C[A[i]] -= d;
        }
    }
    std::cout << ans << nl;
}
