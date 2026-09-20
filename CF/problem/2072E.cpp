//Fri Jun  5 09:00:33 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
std::vector<int> a(501);
void solve() {
    int k;
    std::cin >> k;
    std::vector<int> ans;
    int tot = 0;
    while (k) {
        for (int i = 500; i >= 2; --i) {
            while (k >= a[i]) {
                k -= a[i];
                ans.push_back(i);
                tot += i;
            }
        }
    }
    std::cout << tot << nl;
    int x = 0, y = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            std::cout << x << " " << y++ << nl;
        }
        x++;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    for (int i = 2; i <= 500; ++i) {
        a[i] = i * (i - 1) / 2;
    }
    while (t--) solve();
}
