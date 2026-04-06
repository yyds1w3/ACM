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
constexpr int N = 5000;
struct BigInt {
    std::vector<int> a;
    BigInt(int x = 0) {
        a.assign(N, 0);
        for (int i = 0; x; ++i) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt& operator*=(const int b) {
        for (int i = 0; i < N; ++i) {
            a[i] = a[i] * b;
        }
        for (int i = 0; i < N - 1; ++i) {
            if (a[i] > 9) {
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
            }
        }
        return *this;
    }
    int& operator[](int i) {
        return a[i];
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    BigInt D;
    int k = 0;
    int idx = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '.') {
            k = s.size() - 1 - i;
        }else {
            D[idx++] = s[i] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        D *= 2;
    }
    if (D[k-1] >= 5) {
        D[k]++;
    }
    for (int i = k; i < N - 1; ++i) {
        if (D[i] > 9) {
            D[i] -= 10;
            D[i + 1]++;
        }
    }
    bool f = false;
    for (int i = N - 1; i >= k; --i) {
        if (D[i] != 0) {
            f = true;
        }
        if (f) {
            std::cout << D[i];
        }
    }
    std::cout << nl;
}
