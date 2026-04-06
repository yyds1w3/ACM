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

constexpr int N = 4000;
struct BigInt {
    int a[N];
    BigInt(int x = 0) : a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt &operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }
    BigInt operator/(int x) const {
        BigInt res = *this;
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                res.a[i - 1] += res.a[i] % x * 10;
            }
            res.a[i] /= x;
        }
        return res;
    }
    bool operator<(const BigInt &rhs) const {
        for (int i = N - 1; i >= 0; i--) {
            if (a[i] != rhs.a[i]) {
                return a[i] < rhs.a[i];
            }
        }
        return false;
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    int t = N - 1;
    while (t > 0 && a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        std::cin >> a[i].first >>  a[i].second;
    }
    std::sort(a.begin() + 1, a.end(), [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
        return lhs.first * lhs.second < rhs.first * rhs.second;
    });
    BigInt p = a[0].first;
    BigInt ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, (p / a[i].second));
        p *= a[i].first;
    }
    std::cout << ans << nl;
}
