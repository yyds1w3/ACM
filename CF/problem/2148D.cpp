//Wed May 13 06:25:38 PM CST 2026
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
    std::vector<int> odd, even;
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
        tot += x;
    }
    if (odd.empty()) {
        std::cout << 0 << nl;
        return;
    }

    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());

    tot -= std::accumulate(odd.begin(), odd.begin() + odd.size() / 2, 0LL);
    std::cout << tot << nl;
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
