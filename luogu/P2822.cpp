// 二维前缀和
// 杨辉三角
// 先杨辉三角初始化，除以模，再二维前缀和使得查询O(1)
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
const int MAXN = 2e3 + 1;
const int MAXT = 1e4 + 1;
int C[MAXN][MAXN];
ll pi[MAXN][MAXN];
struct query{
    int n, m;
};
query q[MAXT];
int k;
void init(int n){
    C[0][0] = 1 % k;
    for (int i = 1; i <= n; ++i){
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % k; // % >> +优先级
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            pi[i][j] = pi[i-1][j] + pi[i][j-1] - pi[i-1][j-1] + (j <= i && C[i][j] == 0 ? 1 : 0);
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
    cin >> tt >> k;
    int mx = 0;
    for (int i = 1; i <= tt; ++i){
        cin >> q[i].n >> q[i].m;
        mx = max(mx, q[i].n);
    }
    debug(mx);
    init(mx);
    for (int i = 1; i <= tt; ++i){
        cout << pi[q[i].n][min(q[i].n, q[i].m)] << "\n";// 不能把超过n的零区域也计算 !!!
    }
    return 0;
}
