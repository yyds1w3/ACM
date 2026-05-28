//Thu Apr 30 03:19:52 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    std::vector<bool> mid(n + 1);
    for (int i = std::max(0, n - k); i < std::min(n, k); ++i) {
        mid[a[i]] = true;
    }
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        if (i < n - k || i >= k) {
            if (a[i] != b[i] && b[i] != -1) {
                std::cout << "NO" << nl;
                return;
            }
        }else {
            if (b[i] != -1) {
                if (!mid[b[i]]) {
                    std::cout << "NO" << nl;
                    return;
                }else {
                    cnt[b[i]]++;
                    if (cnt[b[i]] > 1) {
                        std::cout << "NO" << nl;
                        return;
                    }
                }
            }
        }
    }
    std::cout << "YES" << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
