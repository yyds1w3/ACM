#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
int res[501], base[501], temp[501];
void mult(int *a, int *b){
    memset(temp, 0, sizeof(temp));
    for (int i = 1; i <= 500; ++i){
        if (a[i] == 0) continue;
        for (int j = 1; j <= 501 - i; ++j){
            temp[i + j - 1] += a[i] * b[j];
        }
    }
    for (int i = 1; i <= 500; ++i){
        if (i < 500) temp[i+1] += temp[i] / 10;
        temp[i] %= 10;
    }
    memcpy(a, temp, sizeof(temp));
}

void qpow(int p){
    memset(res, 0, sizeof(res));
    res[1] = 1;
    memset(base, 0, sizeof(base));
    base[1] = 2;
    while (p){
        if (p & 1) mult(res, base);
        mult(base, base);
        p >>= 1;
    }
}
void solve() {
    int p; cin >> p; // log_10(2^p) + 1 = p * (log_10(2)) + 1;
    cout << int(log10(2) * p + 1) << "\n";
    qpow(p);
    res[1] -= 1;
    for (int i = 500; i >= 1; --i) {
        cout << res[i];
        if ((500 - i + 1) % 50 == 0) cout << "\n";
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
