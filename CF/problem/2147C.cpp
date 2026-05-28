//Sat May  9 05:35:53 PM CST 2026
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
    std::string s;
    std::cin >> s;
    int lst = -2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i - lst > 2){
                if (cnt % 2 == 1) {
                    std::cout << "NO" << nl;
                    return;
                }
                cnt = 1;
            }else if (i - lst == 2) {
                if (cnt) cnt++;
            }else {
                cnt = 0;
                // 之要有连续的00, 不需要考虑有多少个01了
            }
            lst = i;
        }
    }
    if (lst < n - 1 && cnt % 2 == 1) {
        std::cout << "NO" << nl;
        return;
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
