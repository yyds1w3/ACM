//Thu Apr 30 08:56:51 PM CST 2026
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
        int n, x, y;
        std::cin >>n >> x >> y;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        // [0, x) [x, y) [y, n);
        std::vector<int> pre(a.begin(), a.begin() + x);
        std::vector<int> mid(a.begin() + x, a.begin() + y);
        pre.insert(pre.end(), a.begin() + y, a.end());
        int mn = 1e9;
        int mn_id = -1;
        for (int i = 0, sz = mid.size(); i < sz; ++i) {
            if (mid[i] < mn) {
                mn = mid[i];
                mn_id = i;
            }
        }
        int psz = pre.size();
        int inst_id = psz;
        for (int i = 0 ; i < psz ; ++i) {
            if (pre[i] > mn) {
                inst_id = i;
                break;
            }
        }
        for (int i = 0; i < inst_id; ++i) {
            std::cout << pre[i] << " ";
        }
        for (int len = 1, sz = mid.size(); len <= sz; ++len) {
            std::cout << mid[(mn_id + len - 1) % sz] << " ";
        }
        for (int i = inst_id; i < psz; ++i) {
            std::cout << pre[i] << " ";
        }
        std::cout << nl;
    }
}
