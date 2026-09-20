//Fri Jun 12 08:49:43 PM CST 2026
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
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::vector<int> l(n, -1), r(n, -1);
    std::vector<int> stk(n);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        int lst = -1;
        while (top >= 0 && p[i] < p[stk[top]]) {
            lst = stk[top];
            top--;
        }
        if (top >= 0) r[stk[top]] = i;
        if (lst >= 0) l[i] = lst;
        stk[++top] = i;
    }
    i64 ansl = 0, ansr = 0;
    for (int i = 0; i < n; ++i) {
        ansl ^= (1LL * (i + 1) * (l[i] + 2));
        ansr ^= (1LL * (i + 1) * (r[i] + 2));
    }
    std::cout << ansl << " " << ansr << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
