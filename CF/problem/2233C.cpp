//Tue Jun  9 11:17:47 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    std::vector<int> stk;
    std::vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        }else {
            if (!stk.empty()) {
                a[stk.back()] = 1;
                a[i] = 2;
                stk.pop_back();
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (k <= 0) break;
        if (s[i] == '(') {
            if (!a[i]) break;
            k--;
            vis[i] = true;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (k <= 0) break;
        if (s[i] == ')') {
            if (!a[i]) break;
            k--;
            vis[i] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) std::cout << 1;
        else std::cout << 0;
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
