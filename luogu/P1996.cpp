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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        R[i] = (i + 1) % n;
        L[i] = (i - 1 + n) % n;
    }
    int i, cnt = 0;
    for (; R[i] != i; i = R[i]) {
        cnt++;
        if (cnt % m == 0) {
            R[L[i]] = R[i];
            L[R[i]] = L[i];
            std::cout << i + 1 << " ";
        }
    }
    std::cout << R[i] + 1;
}
