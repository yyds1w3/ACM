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

map<ll, ll> nums;
void solve() {
    int a, b, q;
    cin >> a >> b >> q;
    for (int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;
        ll ans = -1;
        for (int j = l; j <= r; ++j){
            if (nums.count(j) == 0){
                nums[j] = (j % a + j % b);
            }
            ans = max(nums[j], ans);
        }
        cout << ans << "\n";
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
