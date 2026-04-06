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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> stk(n);
    std::vector<int> ans(n);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        while (top >= 0 && a[stk[top]] < a[i]) {
            ans[stk[top]] = i + 1;
            top--;
        }
        stk[++top] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
}
