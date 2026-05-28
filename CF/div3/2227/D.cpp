//Fri May  1 12:39:09 PM CST 2026
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
        int n;
        std::cin >> n;
        std::vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            std::cin >> a[i];
        }
        std::vector<std::vector<int>> pos(n);
        for (int i = 0; i < 2 * n; ++i) {
            pos[a[i]].push_back(i);
        }
        // 最大的mex一定从0开始的
        int ans = 1;
        int p = pos[0][0];
        std::vector<bool> vis(n + 1);
        for (int i = 1; i < n; ++i) {
            if (p - i < 0 || p + i >= 2 * n) break;
            if (a[p-i] == a[p+i]) {
                vis[a[p-i]] = true;
            }else {
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans = std::max(ans, i);
                break;
            }
        }
        p = pos[0][1];
        vis.assign(n, false);
        for (int i = 1; i < n; ++i) {
            if (p - i < 0 || p + i >= 2 * n) break;
            if (a[p-i] == a[p+i]) {
                vis[a[p-i]] = true;
            }else {
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans = std::max(ans, i);
                break;
            }
        }
        vis.assign(n, false);
        int p1 = pos[0][0];
        int p2 = pos[0][1];
        bool f = true;
        int l = p1 + 1;
        int r = p2 - 1;
        while (l <= r) {
            if (a[l] == a[r]) {
                vis[a[l]] = true;
                l++;
                r--;
            }else {
                f = false;
                break;
            }
        }
        if (f) {
            for (int i = 1; i < n; ++i) {
                if (p1 - i < 0 || p2 + i >=2 * n) break;
                if (a[p1 - i] == a[p2 + i]) {
                    vis[a[p1 - i]] = true;
                }else {
                    break;
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    ans = std::max(ans, i);
                    break;
                }
            }
        }
        std::cout << ans << nl;
    }
}
