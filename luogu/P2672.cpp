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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N;
    std::cin >> N;
    std::vector<int> S(N + 1);
    std::vector<std::pair<int, int>> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> S[i];
    }
    for (int i = 1; i <= N; ++i) {
        std::cin >> A[i].first;
        A[i].second = i;
    }
    std::sort(A.begin() + 1,  A.end(), std::greater<std::pair<int, int>>());
    std::vector<int> pre(N + 1);
    std::vector<int> mx_S(N + 1);
    std::vector<int> suff(N + 2);
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + A[i].first;
        mx_S[i] = std::max(mx_S[i - 1], S[A[i].second]);
    }
    for (int i = N; i >= 1; --i) {
        suff[i] = std::max(suff[i + 1], 2 * S[A[i].second] + A[i].first);
    }
    for (int i = 1; i <= N; ++i) {
        std::cout << std::max(pre[i] + 2 * mx_S[i], pre[i - 1] + suff[i]) << nl;
    }
}
