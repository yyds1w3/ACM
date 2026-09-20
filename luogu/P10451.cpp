//Wed Jul 22 10:13:04 AM CST 2026
#include <bits/stdc++.h>
#define nl std::endl
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
bool compare(int a, int b)
{
    std::cout << "? " << a << ' ' << b << nl;
    bool t;
    std::cin >> t;
    return t;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    a.push_back(1);
    for (int i = 1; i < n; ++i) {
        int l = 0, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (compare(a[mid], i + 1)) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        a.insert(a.begin() + l, i + 1);
    }
    std::cout << "! ";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
