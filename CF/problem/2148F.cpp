//Wed May 13 07:07:58 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    int mxc = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> a[i][j]; 
        }
        mxc = std::max(mxc, k);
    }
    std::vector<int> mn(mxc, 1e9);
    std::vector<std::vector<int>> mnv(mxc);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            mn[j] = std::min(mn[j], a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] == mn[j]) {
                mnv[j].push_back(i);
            }
        }
    }
    std::vector<int> ans(mxc);
    std::vector<int> cands; // 关键数组
    bool f = true;
    for (int j = 0; j < mxc; ++j) {
        if (f) {
            cands = mnv[j];
            ans[j] = mn[j];
        }else {
            int curMn = 1e9;
            for (int id : cands) {
                curMn = std::min(curMn, a[id][j]);
            }
            ans[j] = curMn;
            std::vector<int> nxt;
            for (int id : cands) {
                if (a[id][j] == curMn) {
                    nxt.push_back(id);
                }
            }
            cands = nxt;
        }
        f = false;
        for (int id : cands) {
            if (a[id].size() == j + 1) {
                f = true;
                break;
            }
        }
    }
    for (int j = 0; j < mxc; ++j) {
        std::cout << ans[j] << " ";
    }
    std::cout << nl;
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
