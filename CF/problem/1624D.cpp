#include <bits/stdc++.h>
#include <cstring>
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
const int MAXN = 2e5 + 1;
int cnt[26];
int pairs;
map<int, int> m;
int n, k; 
bool check(int x) {
    int need = k * (x / 2);
    if (need > pairs) return false;
    if (x % 2 == 0) return true;
    return n - (need * 2) >= k;
}
void solve() {
    cin >> n >> k;
    char c;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        cnt[c - 'a']++;
    }
    pairs = 0;
    for (int i = 0; i < 26; ++i) {
        pairs += cnt[i] / 2;
    }
    int l = 1, r = n / k;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
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
