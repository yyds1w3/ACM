//Sat Jul 25 08:07:46 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }
    std::vector<int> P(n), Q(n);
    for (int i = 0; i < n; ++i) std::cin >> P[i];
    for (int i = 0; i < n; ++i) std::cin >> Q[i];
    i64 a = -1, b = -1;
    i64 idx = 1;
    do {
        bool f1 = true, f2 = true;
        if (a == -1) {
            for (int i = 0; i < n; ++i) {
                if (p[i] != P[i]) {
                    f1 = false;
                    break;
                }
            }
        }
        if (b == -1) {
            for (int i = 0; i < n; ++i) {
                if (p[i] != Q[i]) {
                    f2 = false;
                    break;
                }
            }
        }
        if (a == -1 && f1) a = idx;
        if (b == -1 && f2) b = idx;
        idx++;
    }while (std::next_permutation(p.begin(), p.end()));
    std::cout << std::max(0LL, b - a - 1) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
