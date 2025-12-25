#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
const int MAXN = 1e5 +5;
int a[MAXN];
int x, sz;
// 不严格下降
int get_nlis(){
    vector<int> tail;
    for (int i = 1; i <= sz; ++i){
        auto it = upper_bound(tail.begin(), tail.end(), a[i], greater<int>());
        if (it == tail.end()) tail.push_back(a[i]);
        else *it = a[i];
    }
    return tail.size();
}
// 严格上升
int get_lis(){
    vector<int> tail;
    for (int i = 1; i <= sz; ++i){
        auto it = lower_bound(tail.begin(), tail.end(), a[i]);
        if (it == tail.end()) tail.push_back(a[i]);
        else *it = a[i];
    }
    return tail.size();
}
void solve() {
    while (cin >> x){
        a[++sz] = x;
    }
    cout << get_nlis() << endl;
    cout << get_lis() << endl;
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
