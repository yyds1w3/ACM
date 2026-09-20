//Fri Aug  7 10:38:38 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::pair<int, int>> v;
    int lst = a[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == lst) {
            cnt++;
        }else {
            v.push_back({lst, cnt});
            lst = a[i];
            cnt = 1;
        }
    }
    v.push_back({lst, cnt});
    int m = v.size();
    int mx = 0;
    for (int i = 0; i < m - 1; ++i) {
        if (i < m - 2) {
            if (v[i + 1].second == 1 && v[i].first == v[i+2].first) continue;
        }
        if (i > 0) {
            if (v[i].second == 1 && v[i-1].first == v[i+1].first) continue;
        }
        mx = std::max(mx, (v[i].second >= 2 ? 1 : 0)+ (v[i+1].second >= 2 ? 1 : 0));
    }
    std::cout << m + mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
