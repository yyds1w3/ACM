#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using ui32 = unsigned int;
using i128 = __int128;

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k % 2 == 1){
        for (i64 i = 0; i < k; ++i){
            cout << n << (i == k-1 ? "" : " ");
        }
    }else{
        for (i64 i = 0; i < k-1; ++i){
            cout << n << " ";
        }
        cout << 0;
    }
    cout << endl;
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
