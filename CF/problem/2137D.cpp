//Fri May 15 07:28:27 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    std::vector<std::vector<int>> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        if (b[i] > n) {
            std::cout << -1 << nl;
            return;
        }
        cnt[b[i]].push_back(i);
    }
    std::vector<int> a(n);
    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        if (!cnt[i].empty() && cnt[i].size() % i != 0) {
            std::cout << -1 << nl;
            return;
        }else {
            while (!cnt[i].empty()) {
                for (int j = 0; j < i; ++j) {
                    a[cnt[i].back()] = idx;
                    cnt[i].pop_back();
                }
                idx++;
            }
        }
    }
    for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
    std::cout << nl;
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
