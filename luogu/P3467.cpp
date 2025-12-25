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
const int MAXN = 2.5e5 + 1;
int stk[MAXN], top = 0;
void solve() {
    int n; cin >> n;
    int num = 0;
    for (int i = 1; i <= n; ++i){
        int a,b; cin >> a >> b;
        while (top > 0 && b <= stk[top]){
            if (b == stk[top]) num++;
            top--;
        }
        stk[++top] = b;
    }
    cout << n - num;
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
