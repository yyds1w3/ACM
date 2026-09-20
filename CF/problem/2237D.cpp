//Tue Jun 23 08:47:53 PM CST 2026
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
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(3);
    cnt[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + (s[i] - '0') + 1) % 3;
        cnt[sum]++;
    }
    i64 ans = 1LL * n * (n + 1) / 2;
    for (int i = 0; i < 3; ++i) {
        int k = cnt[i];
        ans -= 1LL * k * (k - 1) / 2;
    }
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n - 1 && s[j] != s[j + 1]) {
            j++;
        }
        int k = j - i + 1;
        if (k & 1) {
            int m = k / 2;
            ans -= 1LL * m * (m - 1) / 2;
            ans -= 1LL * m * (m + 1) / 2;
        }else {
            int m = k / 2;
            ans -= 1LL * 2 * m * (m - 1) / 2;
        }
        i = j + 1;
    } 
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
