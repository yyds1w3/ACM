#include <bits/stdc++.h>
#include <iomanip>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 3e2 + 5;
double dp[MAXN][MAXN][MAXN];
int cnt[4];
int N;
double f(int c3, int c2, int c1) {
    if (c3 == 0 && c2 == 0 && c1 == 0) return 0;
    if (dp[c3][c2][c1] > 0) return dp[c3][c2][c1];
    double ans = 0;
    int total = c3 + c2 + c1;
    // E = 1 + k/N *E(c3) + j/N *E(c2) + i/N *E(c1) + (N-k-j-i)/N *E
    // k+j+i/N *E = 1 + k/N ....
    // E = N/k+j+i + k/k+j+i *E(c3) ....
    ans += (double)N / (c3 + c2 + c1);
    if (c3 > 0) ans += f(c3-1, c2+1, c1) * ((double)c3 / total);
    if (c2 > 0) ans += f(c3, c2-1, c1+1) * ((double)c2 / total);
    if (c1 > 0) ans += f(c3, c2, c1-1) * ((double)c1 / total);
    return dp[c3][c2][c1] = ans;
}
void solve() {
    cin >> N;
    rep(i, 1, N) {
        int a; cin >> a;
        cnt[a]++;
    }
    cout << setprecision(10) << fixed << f(cnt[3], cnt[2], cnt[1]) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
