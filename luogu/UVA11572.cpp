// 双指针模板题
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
const int MAXN = 1e6 + 1;
int a[MAXN];
void solve() {
    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int len = 0;
    for (int l = 1, r = 1; r <= n; ++r){
        while (s.find(a[r]) != s.end()){
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        len = max(len, r - l + 1);
    }
    cout << len << "\n";
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
