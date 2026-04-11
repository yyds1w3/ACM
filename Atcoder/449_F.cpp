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
    int H, W, h, w, N;
    std::cin >> H >> W >> h >> w >> N;
    std::vector<int> R(N), C(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> R[i] >> C[i];
    }
}
