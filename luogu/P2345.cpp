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
const int MAXN = 2e4 + 1;
int n, total_sum;
struct Cow {
    int v, x;
    bool operator<(const Cow& other) const {return v < other.v;}
}a[MAXN];
int tr_cnt[MAXN], tr_sum[MAXN];
int lowbit(int x) {return x &(-x);}
void add(int x, int k, int *tr) {
    while (x < MAXN) {
        tr[x] += k;
        x += lowbit(x);
    }
}
ll ask(int x, int *tr) {
    ll res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) { // 每头奶牛的听力和坐标
        cin >> a[i].v >> a[i].x;
    }
    sort(a + 1, a + 1 + n); // 按照听力从小到大排序
    ll ans = 0;
    for (int i = 1; i <= n; ++i){ // 按照听力从小到大处理, 每头奶牛处理当前存在的奶牛就可以了
        int ln = ask(a[i].x, tr_cnt); // 已经处理的奶牛中， 坐标在左边的数量
        int ls = ask(a[i].x, tr_sum); // 坐标的左边的坐标和
        ans += (ll)a[i].v * (ln * a[i].x - ls); // 公式代入
        int rn = i - 1 - ln; // 已经处理的奶牛中， 坐标在右边的数量
        int rs = ask(MAXN - 1, tr_sum) - ls; // 坐标在右边的坐标和
        ans += (ll)a[i].v * (rs - rn * a[i].x); // 
        add(a[i].x, 1, tr_cnt); // 单点修改
        add(a[i].x, a[i].x, tr_sum); // 单点修改
    }
    cout << ans << "\n";

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
