//Mon Jun 15 02:57:08 PM CST 2026
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
    i64 x, y;
    std::cin >> x >> y;
    if (x == y) {
        std::cout << "YES" << nl;
        return;
    }
    if (!(y & 1)) {
        std::cout << "NO" << nl;
        return;
    }
    std::vector<int> a, b;
    int cnt = 0;
    while (x) {
        if (x & 1) {
            a.push_back(cnt);
            cnt = 0;
        }else {
            cnt++;
        }
        x >>= 1;
    }
    std::reverse(a.begin(), a.end());
    cnt = 0;
    while (y) {
        if (y & 1) {
            b.push_back(cnt);
            cnt = 0;
        }else {
            cnt++;
        }
        y >>= 1;
    }
    std::reverse(b.begin(), b.end());
    if ((int)b.size() < (int)a.size()) {
        std::cout << "NO" << nl;
        return;
    }
    // debug(a);
    // debug(b);
    bool f = false;
    {
        int len = a.size();
        for (int i = 0; i + len <= (int)b.size(); ++i) {
            bool ok = true, ok1 = true, ok2 = true;
            for (int j = 0; j < len; ++j) {
                if (a[j] != b[i + j]) {
                    ok1 = false;
                }
            }
            for (int j = len - 1; j >= 0; --j) {
                if (a[j] != b[i + len - 1 - j]) {
                    ok2 = false;
                }
            }
            ok = ok1 || ok2;
            for (int j = 0; j < i; ++j) {
                if (b[j] != 0) {
                    ok = false;
                }
            }
            for (int j = i + len; j < (int)b.size(); ++j) {
                if (b[j] != 0) {
                    ok = false;
                }
            }
            if (ok == true) f = true; 
        }
    }
    {
        a.pop_back();
        int len = a.size();
        for (int i = 0; i + len <= (int)b.size(); ++i) {
            bool ok = true, ok1 = true, ok2 = true;
            for (int j = 0; j < len; ++j) {
                if (a[j] != b[i + j]) {
                    ok1 = false;
                }
            }
            for (int j = len - 1; j >= 0; --j) {
                if (a[j] != b[i + len - 1 - j]) {
                    ok2 = false;
                }
            }
            ok = ok1 || ok2;
            for (int j = 0; j < i; ++j) {
                if (b[j] != 0) {
                    ok = false;
                }
            }
            for (int j = i + len; j < (int)b.size(); ++j) {
                if (b[j] != 0) {
                    ok = false;
                }
            }
            if (ok == true) f = true; 
        }
    }
    if (f) {
        std::cout << "YES" << nl;
    }else {
        std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
