// 单点修改冒泡排序
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
struct st {
    int val;
    int id;
    bool operator<(const st& other) const{
        if (val != other.val) return val < other.val;
        return id < other.id;
    }
}a[8001];
int pos[8001];
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        pos[a[i].id] = i;
    }
    for (int i = 1; i <= q; ++i){
        int op, x1, x2;
        cin >> op;
        if (op == 1){
            cin >> x1 >> x2;
            int sa = pos[x1];
            if (x2 > a[sa].val){
                a[sa].val = x2;
                if (sa == n) continue;
                while(a[sa].val > a[sa+1].val || (a[sa].val == a[sa+1].val && a[sa].id > a[sa+1].id)){
                    pos[x1] = sa + 1;
                    pos[a[sa + 1].id] = sa;
                    swap(a[sa], a[sa + 1]);
                    sa++;
                    if (sa == n) break;
                }
            }else{
                a[sa].val = x2;
                if (sa == 1) continue;
                while(a[sa].val < a[sa-1].val || (a[sa].val == a[sa-1].val && a[sa].id < a[sa-1].id)){
                    pos[x1] = sa - 1;
                    pos[a[sa - 1].id] = sa;
                    swap(a[sa], a[sa -1]);
                    sa--;
                    if (sa == 1) break;
                }
            }
        }else{
            cin >> x1;
            cout << pos[x1] << "\n";
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
