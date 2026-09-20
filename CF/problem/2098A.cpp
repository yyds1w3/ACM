//Wed Jun 17 12:48:44 PM CST 2026
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
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(10);
    for (int i = 0; i < 10; ++i) {
        cnt[s[i] - '0']++;
    }
    std::string a;
    for (int i = 0;i < 10; ++i) {
        for (int j = 9 - i; j < 10; ++j) {
            if (cnt[j] > 0) {
                a += '0' + j;
                cnt[j]--;
                break;
            }
        }
    }
    std::cout << a << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
