//Tue Aug 25 11:47:20 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sa ^= a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        sb ^= b[i];
    }
    if (sa == sb) {
        bool ok = true;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) std::cout << "YES" << nl;
        else std::cout << "NO" << nl;
    }else {
        int target = sa ^ sb;
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == target) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            for (int i = 0; i < n; ++i) {
                if (i != idx) a[i] ^= a[idx];
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) std::cout << "YES" << nl;
        else std::cout << "NO" << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
