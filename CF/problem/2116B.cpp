//Sun May 31 11:09:39 AM CST 2026
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
const int MOD = 998244353;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), q(n);
    std::vector<std::pair<int, int>> pre1(n), pre2(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (i == 0) pre1[i] = {p[i], i};
        else {
            if (p[i] > pre1[i - 1].first) {
                pre1[i] = {p[i], i};
            }else {
                pre1[i] = pre1[i-1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
        if (i == 0) pre2[i] = {q[i], i};
        else {
            if (q[i] > pre2[i - 1].first) {
                pre2[i] = {q[i], i};
            }else {
                pre2[i] = pre2[i-1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (pre1[i].first > pre2[i].first) {
            std::cout << (qpow(2, pre1[i].first) + qpow(2, q[i - pre1[i].second])) % MOD << " ";
        }else if (pre1[i].first == pre2[i].first) {
            if (q[i - pre1[i].second] >= p[i - pre2[i].second]) {
            std::cout << (qpow(2, pre1[i].first) + qpow(2, q[i - pre1[i].second])) % MOD << " ";
            }else {
            std::cout << (qpow(2, pre2[i].first) + qpow(2, p[i - pre2[i].second])) % MOD << " ";
            }
        }else if (pre1[i].first < pre2[i].first){
            std::cout << (qpow(2, pre2[i].first) + qpow(2, p[i - pre2[i].second])) % MOD << " ";
        }
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
    while (t--) solve();
}
