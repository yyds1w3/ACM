//Tue May  5 09:24:14 PM CST 2026
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
const int INF = 1e9;

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
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<int> a(n), b(m);
        std::string s;
        std::map<int, int> mp;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];
        std::cin >> s;
        for (int i = 0, sz = s.size(), pos = 0; i < sz; ++i) {
            if (s[i] == 'L') {
                pos--;
            }else {
                pos++;
            }
            if (mp[pos] == 0) {
                mp[pos] = i + 1;
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::vector<int> die(s.size() + 1);
        for (int i = 0, sz = a.size(); i < sz; ++i) {
            auto rt = std::lower_bound(b.begin(), b.end(), a[i]); // >=
            auto lt = std::prev(std::upper_bound(b.begin(), b.end(), a[i])); // <=
            int ld, rd;
            if (rt == b.end()) {
                rd = INF;
            }else {
                rd = *rt - a[i];
            }
            if (lt == prev(b.begin())) {
                ld = -INF;
            }else {
                ld = *lt - a[i];
            }
            int t = INF;
            if (rd == 0 || ld == 0) {
                t = 0;
            }else {
                if (mp[ld] == 0) mp[ld] = INF;
                if (mp[rd] == 0) mp[rd] = INF;
                t = std::min(mp[ld], mp[rd]);
            }
            if (t <= (int)s.size()) {
                die[t]++;
            }
        }
        for (int i = 1, sz = die.size(); i < sz; ++i) {
            die[i] += die[i-1];
            std::cout << n - die[i] << " ";
        }
        std::cout << nl;
    }
}
