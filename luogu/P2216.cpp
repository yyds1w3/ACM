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
int a, b, n;
int mat[1001][1001];
int mat_x[1001][1001];
int mat_n[1001][1001];
deque<int> qx, qn;
void solve() {
    cin >> a >> b >> n;
    for (int i = 1; i <= a; ++i){
        qx.clear();
        qn.clear();
        for (int j = 1; j <= b; ++j){
            cin >> mat[i][j];
            while(!qx.empty() && mat[i][j] >= mat[i][qx.back()])
                qx.pop_back();
            while(!qn.empty() && mat[i][j] <= mat[i][qn.back()])
                qn.pop_back();
            qx.push_back(j);
            qn.push_back(j);
            if (j - qx.front() >= n) qx.pop_front();
            if (j - qn.front() >= n) qn.pop_front();
            if (j >= n) {
                mat_x[i][j-n+1] = mat[i][qx.front()];
                mat_n[i][j-n+1] = mat[i][qn.front()];
            }
        }
    }
    for (int j = 1; j <= b - n + 1; ++j){
        qx.clear();
        qn.clear();
        for (int i = 1; i <= a; ++i){
            while (!qx.empty() && mat_x[i][j] >= mat_x[qx.back()][j])
                qx.pop_back();
            while (!qn.empty() && mat_n[i][j] <= mat_n[qn.back()][j])
                qn.pop_back();
            qx.push_back(i);
            qn.push_back(i);
            if (i - qx.front() >= n) qx.pop_front();
            if (i - qn.front() >= n) qn.pop_front();
            if (i >= n){
                mat_x[i-n+1][j] = mat_x[qx.front()][j];
                mat_n[i-n+1][j] = mat_n[qn.front()][j];
            }
        }
    }
    int ans = 2e9;
    for (int i = 1; i <= a - n + 1; ++i){
        for (int j = 1; j <= b - n + 1; ++j){
            ans = min(mat_x[i][j] - mat_n[i][j], ans);
        }
    }
    cout << ans;
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
