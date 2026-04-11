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
    std::vector<int> a(n);
    bool r1 = true;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (std::abs(a[i]) != std::abs(a[i - 1])) {
            r1 = false;
        }
    }
    if (r1) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) pos++;
            else if(a[i] < 0) pos--;
        }
        if (std::abs(pos) == n || std::abs(pos) <= 1) std::cout << "Yes" << nl;
        else std::cout << "No" << nl;
        return;
    }
    std::sort(a.begin(), a.end(), [](int x, int y) {
        return std::abs(x) < std::abs(y);
    });
    for (int i = 1; i < n - 1; ++i) {
        if (1LL * a[i - 1] * a[i + 1] != 1LL * a[i] * a[i]) {
            std::cout << "No" << nl;
            return;
        }
    }
    std::cout << "Yes" << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
