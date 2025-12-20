#include <bits/stdc++.h>
#include <cstring>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct A{
    ll mat[2][2];
    A(){
        memset(mat, 0, sizeof(mat));
    }
    void identity(){
        memset(mat, 0, sizeof(mat));
        mat[0][0] = mat[1][1] = 1;
    }

    A operator* (const A& other) const {
        A res;
        for (int i = 0; i < 2; ++i) {
            for (int k = 0; k < 2; ++k) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < 2; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]);
                }
            }
        }
        return res;
    }
    A qpow(A a, ll b){
        A res;
        res.identity();
        while (b){
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    if ( n <= 2) {cout << "1\n"; return;}
    A res;
    res.mat[0][0] = 1; res.mat[0][1] = 1;
    res.mat[1][0] = 1; res.mat[1][1] = 0;
    A ans = res.qpow(res, n - 2);
    cout << ans.mat[0][0] + ans.mat[0][1] << endl;
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
