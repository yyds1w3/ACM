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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
int get_prime_cnt(int x) {
    int cnt = 0;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0){
            x/= i;
            cnt++;
        }
    }
    if (x > 1) cnt++;
    return cnt;
}
void solve() {
    int a, b, k; cin >> a >> b >> k;
    int k_mx = get_prime_cnt(a) + get_prime_cnt(b);
    if (k == 1) {
        if (a != b && ((a % b == 0) || (b % a == 0))) {
            cout << "YES\n";
        }else cout << "NO\n";
        return;
    }
    if (k <= k_mx) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
