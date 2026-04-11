//2026-04-09 20:53:48
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
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> st(n);
    std::vector<int> ans(n, -1);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && a[st[top]] < a[i]) {
            ans[st[top]] = i;
            top--;
        }
        st[++top] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << " ";
    }
}
