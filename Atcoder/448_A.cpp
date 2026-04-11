#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, X;
    std::cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int A;
        std::cin >> A;
        if (A < X) {
            X = A;
            std::cout << 1 << nl;
        }else {
            std::cout << 0 << nl;
        }
    }
}
