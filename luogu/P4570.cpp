//Mon Apr 27 08:02:59 PM CST 2026
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

struct stone {
    i64 num;
    i64 magic;
    bool operator<(const stone& other) {
        return magic > other.magic;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n;
    std::cin >> n;
    std::vector<stone> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].num >> a[i].magic;
    }
    std::sort(a.begin(), a.end());
    std::vector<i64> d(64);
    i64 ans = 0;
    for (auto [num, magic] : a) {
        bool success = false;
        for (int i = 63; i >= 0; --i) {
            if ((num >> i) & 1) {
                if (!d[i]) {
                    d[i] = num;
                    success = true;
                    break;
                }else {
                    num ^= d[i];
                }
            }
        }
        if (success) ans += magic;
    }
    std::cout << ans << nl;
}
