#include <bits/stdc++.h>
#include <utility>
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
const int MAXN = 1e5 + 1;
struct lu{
    ll a, b, c, d;
};
int p[MAXN];
lu c[MAXN];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> p[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        cin >> c[i].a >> c[i].b >> c[i].c;
    }
    for (int i = 1; i <= m - 1; ++i){
        int a = p[i];
        int b = p[i+1];
        if ( a > b ) swap(a, b);
        // [a, b)
        c[a].d++;
        c[b].d--;
    }
    ll cost = 0;
    for (int i = 1; i <= n-1; ++i){
        c[i].d += c[i-1].d;
        cost += min(c[i].d*c[i].a, c[i].d*c[i].b + c[i].c);
    }
    cout << cost << endl;


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
