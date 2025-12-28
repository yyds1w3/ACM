#include <algorithm>
#include <bits/stdc++.h>
#include <mutex>
#include <vector>
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
const int MAXN = 5e4 + 1;
int n, total_sum;
struct Cow {
    int v, x;
    bool operator<(const Cow& other) const {return v < other.v;}
}a[MAXN];
ll tr_cnt[MAXN], tr_sum[MAXN];
vector<ll> tr_raw;
int lowbit(int x) {return x &(-x);}
void add(int x, int k, ll *tr) {
    while (x < MAXN) {
        tr[x] += k;
        x += lowbit(x);
    }
}
ll ask(int x, ll *tr) {
    ll res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
int get_id(int x){
    return lower_bound(tr_raw.begin(), tr_raw.end(), x) - tr_raw.begin() + 1;
}


void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) { // 每头奶牛的听力和坐标
        cin >> a[i].v >> a[i].x;
        tr_raw.push_back(a[i].x);
    }
    sort(a + 1, a + 1 + n); // 按照听力从小到大排序
    sort(tr_raw.begin(), tr_raw.end());
    tr_raw.erase(unique(tr_raw.begin(), tr_raw.end()), tr_raw.end()); // 离散化x坐标
    int m = tr_raw.size();
    
    ll ans = 0;
    for (int i = 1; i <= n; ++i){ // 按照听力从小到大处理, 每头奶牛处理当前存在的奶牛就可以了
        int v = a[i].v;
        int x = a[i].x;
        int rx = get_id(x);
        ll ln = ask(rx, tr_cnt); // 已经处理的奶牛中， 坐标在左边的数量
        ll ls = ask(rx, tr_sum); // 坐标的左边的坐标和
        ans += (ll)v * (ln * a[i].x - ls); // 公式代入
        ll rn = i - 1 - ln; // 已经处理的奶牛中， 坐标在右边的数量
        ll rs = ask(m, tr_sum) - ls; // 坐标在右边的坐标和
        ans += (ll)v * (rs - rn * a[i].x); // 
        add(rx, 1, tr_cnt); // 单点修改
        add(rx, a[i].x, tr_sum); // 单点修改
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
