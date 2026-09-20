//Sat May 30 10:56:34 PM CST 2026
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
    i64 n, x, s;
    std::cin >> n >> x >> s;
    std::string ss;
    std::cin >> ss;
    std::vector<i64> desk;
    int c0 = x;
    int ca = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ss[i] == 'I') {
            if (c0 > 0) {
                c0--;
                if (s > 1) desk.push_back(s - 1);
                ans++;
            }
        }else if (ss[i] == 'E') {
            if (!desk.empty()) {
                desk.back()--;
                if (desk.back() == 0) {
                    desk.pop_back();
                }
                ans++;
            }else if (ca > 0 && c0 > 0) {
                ca--;
                c0--;
                if (s > 1) desk.push_back(s - 1);
                ans++;
            }
        }else {
            if (!desk.empty()) {
                desk.back()--;
                if (desk.back() == 0) {
                    desk.pop_back();
                }
                ca++;
                ans++;
            }else if (c0 > 0) {
                c0--;
                if (s > 1) desk.push_back(s - 1);
                ans++;
            }
        }
    }
    std::cout << ans << nl;
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
    while (t--) solve();
}
