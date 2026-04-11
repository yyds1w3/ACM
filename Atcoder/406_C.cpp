#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n; 
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::pair<char, int>> v;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i+1]) {
            if (v.empty() || v.back().first == '>') {
                v.push_back({'<', 1});
            }else {
                v.back().second++;
            }
        }else {
            if (v.empty() || v.back().first == '<') {
                v.push_back({'>', 1});
            }else {
                v.back().second++;
            }
        }
    }
    i64 ans = 0;
    int sz = v.size();
    for (int i = 1; i < sz - 1; ++i) {
        if (v[i].first == '>') {
            ans += (i64)v[i-1].second * v[i+1].second;
        }
    }
    std::cout << ans << nl;
}
