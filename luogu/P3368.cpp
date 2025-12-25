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
const int MAXN = 5e5 + 5;
int n, m;
int tree[MAXN];
int lowbit(int x){
    return x & (-x);
}
void add(int x, int k){
    while (x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}
int ask(int x){
    int ans = 0;
    while (x){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    int last = 0;
    for (int i = 1; i <= n; ++i){
        int cur;
        cin >> cur;
        add(i, cur - last);
        last = cur;
    }
    for (int i = 1; i <= m; ++i){
        int op;
        cin >> op;
        if (op == 1){
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }else{
            int x;
            cin >> x;
            cout << ask(x) << endl;
        }
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
