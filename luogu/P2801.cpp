//Fri May 29 08:39:28 PM CST 2026
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
    i64 n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    i64 bsz = std::sqrt(n);
    i64 bcnt = (n - 1) / bsz + 1;
    std::vector<i64> tag(bcnt);
    std::vector<i64> pos(n);
    std::vector<std::vector<i64>> blk(bcnt);
    for (i64 i = 0; i < n; ++i) {
        std::cin >> a[i];
        pos[i] = i / bsz;
        blk[pos[i]].push_back(a[i]);
    }
    for (i64 i = 0; i < bcnt; ++i) {
        std::sort(blk[i].begin(), blk[i].end());
    }
    auto rebuild = [&](i64 idx) -> void {
        i64 l = idx * bsz;
        i64 r = (idx + 1) * bsz;
        blk[idx].clear();
        for (i64 i = l; i < r; ++i) {
            blk[idx].push_back(a[i]);
        }
        std::sort(blk[idx].begin(), blk[idx].end());
    };

    while (q--) {
        char op;
        std::cin >> op;
        if (op == 'M') {
            i64 l, r;
            i64 w;
            std::cin >> l >> r >> w;
            l--, r--;
            i64 p = pos[l], q = pos[r];
            if (p == q) {
                for (i64 i = l; i <= r; ++i) {
                    a[i] += w;
                }
                rebuild(p);
            }else {
                for (i64 i = l; i < (p + 1) * bsz; ++i) {
                    a[i] += w;
                }
                rebuild(p);
                for (i64 i = p + 1; i < q; ++i) {
                    tag[i] += w;
                }
                for (i64 i = q * bsz; i <= r; ++i) {
                    a[i] += w;
                }
                rebuild(q);
            }
        }else {
            i64 l, r;
            i64 c;
            std::cin >> l >> r >> c;
            l--, r--;
            i64 p = pos[l], q = pos[r];
            i64 cnt = 0;
            if (p == q) {
                for (i64 i = l; i <= r; ++i) {
                    if (a[i] + tag[p] >= c) cnt++;
                }
            }else{
                for (i64 i = l; i < (p + 1) * bsz; ++i) {
                    if (a[i] + tag[p] >= c) cnt++;
                }
                for (i64 i = p + 1; i < q; ++i) {
                    cnt += blk[i].end() - std::lower_bound(blk[i].begin(), blk[i].end(), c - tag[i]);
                }
                for (i64 i = q * bsz; i <= r; ++i) {
                    if (a[i] + tag[q] >= c) cnt++;
                }
            }
            std::cout << cnt << nl;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    i64 t;
    t = 1;
    while (t--) {
        solve();
    }
}
