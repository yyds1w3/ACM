//Sat May  2 02:54:54 PM CST 2026
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

void solve(){
    int n;
    std::cin >> n;
    // 一棵树,说明每个节点都至少连了一条边
    // 我们从[2, n]一共有n-1个节点去跟前面的节点连边
    // 要满足条件就找极限状态
    std::vector<int> a(n + 1);
    std::vector<int> pre(n + 1, n), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = std::min(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = std::max(suf[i + 1], a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        if (pre[i - 1] > suf[i]) {
            std::cout << "NO" << nl;
            return;
        }
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
