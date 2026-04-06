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
    int s, t;
    std::cin >> s >> t;
    std::vector<int> pi(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        pi[i] = pi[i - 1] + x;
    }
    auto check = [&] (double v) -> bool {
        std::vector<int> q(n + 1);
        int hh = 0, tt = -1;
        auto get_val = [&] (int x) -> double {
            return pi[x] - v * x;
        };
        for (int i = s; i <= n; ++i) {
            int k = i - s;
            while (hh <= tt && get_val(q[tt]) >= get_val(k)) {
                tt--;
            }
            q[++tt] = k;
            while (hh <= tt && q[hh] + t < i) {
                hh++;
            }
            if (get_val(i) - get_val(q[hh]) >= 0){
                return true;
            }
        }
        return false;
    };
    double L = -10000.0, R = 10000.0;
    for (int i = 0; i < 60; ++i) {
        double mid = (L + R) / 2.0;
        if (check(mid)) {
            L = mid;
        }else {
            R = mid;
        }
    }
    std::cout << std::setprecision(3) << std::fixed << L << nl;
}
