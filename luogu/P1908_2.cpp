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
    auto f = [&] (auto self, int l, int r) -> i64 {
        if (r - l == 1) {
            return 0;
        }
        int mid = (l + r) / 2;
        i64 ans = self(self, l, mid) + self(self, mid, r);
        std::vector<int> temp(r - l);
        int i = l, j = mid, k = 0;
        while (i < mid && j < r) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            }else {
                ans += mid - i;
                temp[k++] = a[j++];
            }
        }
        while (i < mid) {
            temp[k++] = a[i++];
        }
        while (j < r) {
            temp[k++] = a[j++];
        }
        for (int p = 0; p < k; ++p) {
            a[p + l] = temp[p];
        }
        return ans;
    };
    std::cout << f(f, 0, n) << nl;
}
