#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
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
    std::vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }
    std::vector<int> pw(N + 1);
    pw[0] = 1;
    for (int i = 1; i <= N; ++i) {
        pw[i] = pw[i-1] * 3;
    }
    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < M; ++i) {
        int K;
        std::cin >> K;

        for (int j = 0; j < K; ++j) {
            int x;
            std::cin >> x;
            x--;
            A[x].push_back(i);
        }
    }
    i64 ans = 1e18;
    for (int mask = 0; mask < pw[N]; ++mask) {
        std::vector<int> cnt(M);
        i64 res = 0;
        for (int i = 0; i < N; ++i) {
            int t = mask / pw[i] % 3;
            for (int _ = 0; _ < t; ++_) {
                for (auto a : A[i]) {
                    cnt[a]++;
                }
                res += C[i];
            }
        }
        if (*std::min_element(cnt.begin(), cnt.end()) >= 2) {
            ans = std::min(ans, res);
        }
    }
    std::cout << ans << nl;
}
