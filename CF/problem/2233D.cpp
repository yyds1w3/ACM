//Tue Jun  9 11:29:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    auto check = [](std::vector<int> v) {
        int N = v.size();
        std::map<int, std::vector<int>> mp;
        for (int i = 0; i < N; ++i) {
            mp[v[i]].push_back(i);
        }
        bool ok = true;
        for (auto [x, l] : mp) {
            if (l.back() - l.front() + 1 != l.size()) {
                ok = false;
            }
        }
        return ok;
    };
    if (check(a)) {
        std::cout << "YES" << nl;
        return;
    }
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
    }
    for (auto [x, l] : mp) {
        if (l.back() - l.front() + 1 != (int)l.size()) {
            {
                std::vector<int> v = a;
                int i = l.front();
                while (v[i] == x) i++;
                std::swap(v[i], v[l.back()]);
                if (check(v)) {
                    std::cout << "YES" << nl;
                    return;
                }
            }
            {
                std::vector<int> v = a;
                int i = l.back();
                while (v[i] == x) i--;
                std::swap(v[i], v[l.front()]);
                if (check(v)) {
                    std::cout << "YES" << nl;
                    return;
                }
            }
            {
                std::vector<int> v = a;
                if (l.front() > 0) {
                    std::swap(v[l.front()-1], v[l.back()]);
                    if (check(v)) {
                        std::cout << "YES" << nl;
                        return;
                    }
                }
            }
            {
                std::vector<int> v = a;
                if (l.back() < n - 1) {
                    std::swap(v[l.front()], v[l.back() + 1]);
                    if (check(v)) {
                        std::cout << "YES" << nl;
                        return;
                    }
                }
            }
            std::cout << "NO" << nl;
            return;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
