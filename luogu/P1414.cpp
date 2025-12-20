// 利用cnt来记录原本数据的出现次数
// ans来记录第k个人的最大gcd
// 用调和筛法来填ans， 稀疏填充（只是填充刚好为k时的最大公因数）
// 需要状态传递, ans[k] = max(ans[k], ans[k+1])来填充空缺
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXV = 1e6 + 1;
const int MAXN = 1e4 + 1;
int cnt[MAXV];
int ans[MAXN];
void solve() {
    int n;
    cin >> n;
    int mx_v = 0;
    for (int i = 0; i < n; ++i){
        int val;
        cin >> val;
        cnt[val]++;
        mx_v = max(mx_v, val);
    }
    for (int g = 1; g <= mx_v; ++g){
        int count = 0;
        for (int mult = g; mult <= mx_v; mult += g){
            count += cnt[mult];
        }
        if (count > 0){
            ans[count] = max(ans[count], g);
        }
    }
    for (int k = n-1; k >= 1; --k){
        ans[k] = max(ans[k], ans[k+1]);
    }
    for (int i = 1; i <= n; ++i){
        cout << ans[i] <<endl;
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
