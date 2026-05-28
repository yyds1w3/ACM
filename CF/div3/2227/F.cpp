//Fri May  1 01:11:07 PM CST 2026
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
        std::vector<int> a(n); // [0, n-1] 的高度
        std::vector<std::vector<int>> pos(n + 1); // [0, n] 高度的列的位置
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            pos[a[i]].push_back(i);
        }
        std::vector<i64> cnt(n + 2), sumpos(n + 2); // 某高度的列的个数 某高度的列的和
        i64 base = 0;
        for (int h = n; h >= 0; --h) {
            cnt[h] = cnt[h + 1];
            sumpos[h] = sumpos[h + 1];
            for (int c : pos[h]) {
                cnt[h]++;
                sumpos[h] += c;
            }
            // (n-1 + n-2 + ... + n-cnt) = n * cnt - (1 + cnt) * cnt / 2 - sumpos;
            // (2 * n - cnt - 1 ) * cnt / 2;
            base += n * cnt[h] - (1 + cnt[h]) * cnt[h] / 2 - sumpos[h];
        }
        i64 add = 0;
        for (int i = 0; i < n; ++i) {
            // n * (cnt - 1) - (cnt - 1) * cnt / 2 - (sumpos - i);
            // delta = -n + cnt + i;
            add= std::max(add, cnt[a[i]] - n + i);
        }
        std::cout << base + add << nl;
    }
}
