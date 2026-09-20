//Tue Aug  4 10:38:23 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::pair<int, int>> v;
    int now = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] - 'a' != now) {
            if (now != -1) v.push_back({now, cnt});
            now = s[i] - 'a';
            cnt = 1;
        }else cnt++;
    }
    v.push_back({now, cnt});
    int c = 0;
    for (int i = 1; i < (int)v.size() - 1; ++i) {
        if (v[i].second == 1) {
            c = std::max(c, 1);
            if (v[i - 1].first == v[i + 1].first) {
                c = std::max(c, 2);
            }
        }
    }
    std::cout << v.size() - c << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
