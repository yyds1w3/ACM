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
void solve(int t) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end() - 1);
    int cnt = 1;
    int curr = a[0];
    int pos = 0;
    while (2 * curr < a.back()) {
        pos = std::upper_bound(a.begin() + pos + 1, a.end() - 1, 2 * curr) - a.begin() - 1;
        if (a[pos] <= curr) {
            std::cout << -1 << nl;
            return;
        }else {
            curr = a[pos];
            cnt++;
        }
    }
    std::cout << cnt + 1 << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while(t--) {
        solve(t);
    }
}
