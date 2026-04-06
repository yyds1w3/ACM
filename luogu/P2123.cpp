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
int sgn(i64 x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    return 1;
}
struct st {
    i64 a, b;
    int d;
    bool operator<(const st& other) const {
        if (d != other.d) {
            return d < other.d;
        }else {
            if (d == -1 || d == 0) {
                return a < other.a;
            }else if (d == 1) {
                return b > other.b;
            }
        }
        return false;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<st> arr(n);
        for (int i = 0; i < n; ++i) {
            i64 a, b;
            std::cin >> a >> b;
            arr[i] = {a, b, sgn(a - b)};
        }
        std::sort(arr.begin(), arr.end());
        i64 c = 0;
        i64 a_sum = 0;
        for (int i = 0, sz = arr.size(); i < sz; ++i) {
            a_sum += arr[i].a;
            c = std::max(c, a_sum) + arr[i].b;
        }
        std::cout << c << nl;
    }

}
