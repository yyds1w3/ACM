#include <bits/stdc++.h>
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
const ll MOD = 1e9 + 7;
ll n, m, k;
struct Matrix {
    ll mat[52][52];
    int _m;
    Matrix(int m) {memset(mat, 0, sizeof(mat)); _m = m;}
    void identity() {for (int i = 0; i < 52; ++i) mat[i][i] = 1;};
    Matrix operator*(const Matrix& other) const {
        Matrix res(_m);
        for (int i = 0; i < _m; ++i) {
            for (int j = 0; j < _m; ++j) {
                for (int k = 0; k < _m; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + 
                        mat[i][k] * other.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
};
Matrix qpow(Matrix a, ll b) {
    Matrix res(m);
    res.identity();
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int get_id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}
void solve() {
    cin >> n >> m >> k;
    Matrix a(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            a.mat[i][j] = 1;
        }
    }
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        a.mat[get_id(s[0])][get_id(s[1])] = 0;
    }
    if (n == 1) {
        cout << m << "\n";
        return;
    }
    Matrix res = qpow(a, n - 1);
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = (ans + res.mat[i][j]) % MOD;
        }
    }
    cout << ans << endl;
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
