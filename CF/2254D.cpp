//Tue Aug  4 11:26:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> b(n);
    std::vector<i64> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        c[i] = b[i];
    }
    std::sort(c.begin(), c.end());
    std::vector<std::pair<i64, int>> v;
    i64 num = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (num == -1 || c[i] != num) {
            if (num != -1) v.push_back({num, cnt});
            num = c[i];
            cnt = 1;
        }else {
            cnt++;
        }
    }
    v.push_back({num, cnt});

    if (v.begin()->first != 0) {
        std::cout << -1 << nl;
        return;
    }
    std::vector<i64> a;
    std::map<i64, i64> pos;
    for (int i = 1; i < v.size(); ++i) {
        if ((v[i].first - v[i-1].first) % v[i-1].second != 0) {
            std::cout << -1 << nl;
            return;
        }
        i64 val = ((v[i].first - v[i-1].first) / v[i-1].second);
        pos[v[i-1].first] = val;
        a.push_back(val);
    }
    for (int i = 1; i < (int)a.size(); ++i) {
        if (a[i] <= a[i-1]) {
            std::cout << -1 << nl;
            return;
        }
    }
    if (a.empty()) {
        pos[v.back().first] = 1;
        a.push_back(1);
    }else {
        pos[v.back().first] = a.back() + 1;
        a.push_back(a.back() + 1);
    }
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        std::cout << pos[b[i]] << " ";
    }
    std::cout << nl;
    

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
