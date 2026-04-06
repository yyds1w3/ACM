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
    int n, k, p, m, x;
    std::cin >> n;
    std::vector<int> L(n + 1), R(n + 1);
    std::vector<bool> erased(n + 1);
    L[0] = 1, R[0] = 1;
    L[1] = 0, R[1] = 0;
    for (int i = 2; i <= n; ++i) {
        std::cin >> k >> p;
        if (p == 0) {
            L[i] = L[k];
            R[i] = k;
            R[L[k]] = i;
            L[k] = i;
        }else {
            R[i] = R[k];
            L[i] = k;
            L[R[k]] = i;
            R[k] = i;
        }
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        if (erased[x]) continue;
        R[L[x]] = R[x];
        L[R[x]] = L[x];
        erased[x] = true;
    }
    for (int i = R[0]; i != 0; i = R[i]) {
        std::cout << i << " ";
    }
}
