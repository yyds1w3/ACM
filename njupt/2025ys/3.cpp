// 1. ai = aj 成对
// 2. 0
// 10 ^ 11 ^ 100 ^ 101 = 101 ^ 101 = 0
// 11 ^ 100 ^ 
// 1 -> second
// 2 -> 2 3 second    2 2 frist
// 3 -> 2 3 4 
// 3 -> 3 5 6
// 3 -> 5 7 8
// 
#include <algorithm>
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
const int MAXN = 101;
ll a[MAXN];
ll base[MAXN];
map<ll, bool> exist;
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        exist[a[i]] = true;
    }
    ll ans = 0;
    for (int t = 1; t <= n / 2; ++t){
        iota(base + 1, base + n + 1, 1);
        while(next_permutation(base + 1, base + 1 + n)){
            for (int i = 1; i <= t; ++i){
                
            }
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
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
