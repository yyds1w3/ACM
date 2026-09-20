//Sat Aug  1 09:23:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    auto check = [&](double x) -> bool {
        std::vector<double> a(n);
        std::vector<int> cnt(n + 1);
        std::vector<double> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'o') {
                a[i] = 1 - x;
                cnt[i + 1] = cnt[i] + 1;
            }else {
                a[i] = -x;
                cnt[i + 1] = cnt[i];
            }
            pref[i + 1] = pref[i] + a[i];
        }
        double mnp = 0;
        int j = 0;
        for (int i = 1; i <= n; ++i) {
            while (j <= i && cnt[i] - k >= cnt[j]) {
                mnp = std::min(pref[j], mnp);
                j++;
            }
            if (cnt[i] >= k && pref[i] - mnp >= 0) return true;
        }
        return false;
    };
    double l = 0, r = 1;
    for (int i = 0; i < 30; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    std::cout << std::setprecision(6) << std::fixed << l << nl;
}
