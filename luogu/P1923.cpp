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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto f = [&] (auto self, int l, int r) -> void {
        if (r - l == 1) {
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid);
        self(self, mid, r);
        int i = l, j = mid, k = 0;
        std::vector<int> temp(r - l);
        while (i < mid && j < r) {
            if (a[i] < a[j]) {
                temp[k++] = a[i++];
            }else temp[k++] = a[j++];
        }
        while (i < mid) {
            temp[k++] = a[i++];
        }
        while (j < r) {
            temp[k++] = a[j++];
        }
        for (int p = 0; p < r - l; ++p) {
            a[l + p] = temp[p];
        }
    };
    f(f, 0, n);
    std::cout << a[k] << nl;
}
