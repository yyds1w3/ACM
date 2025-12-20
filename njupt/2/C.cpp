#include <bits/stdc++.h>
#include <deque>
#include <iomanip>
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
const int MAXN = 1e5 + 5;
int n, s, t;
double a[MAXN], pi[MAXN];
bool check(double x){
    pi[0] = 0;
    for (int i = 1; i <= n; ++i){
        pi[i] = pi[i-1] + a[i] - x;
    }
    deque<int> dq;
    for (int j = s; j <= n; ++j){
        while (!dq.empty() && pi[dq.back()] >= pi[j - s]) dq.pop_back();
        dq.push_back(j - s);
        while (!dq.empty() && dq.front() < j - t) dq.pop_front();
        if (!dq.empty() && pi[j] - pi[dq.front()] >= 0) return true;
    }
    return false;
}
void solve() {
    cin >> n >> s >> t;
    double l = 1e4, r = -1e4;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        l = min(a[i], l);
        r = max(a[i], r);
    }
    for (int i = 0; i < 60; ++i){
        double mid = (l + r) / 2;
        if (check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << setprecision(3) << fixed << l;
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
