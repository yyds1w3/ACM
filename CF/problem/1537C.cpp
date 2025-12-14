// 注意数组越界, 贪心策略,排序后, 边界情况2时应该注意特殊判断
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif
void solve() {
    int n; cin >> n;
    vector<int> moun(n);
    for (int &x : moun) cin >> x;
    sort(moun.begin(), moun.end());
    if (moun.size() == 2) {
        cout << moun[0] << " " << moun[1] << '\n';
        return;
    }
    int mn = 0x3f3f3f3f;
    unsigned int mark = 0;
    for (int i = 0; i < n-1; ++i){
        if (abs(moun[i+1] - moun[i]) < mn){
            mn = abs(moun[i+1] - moun[i]);
            mark = i;
        }
    }
    for (unsigned int i = mark+1; i < moun.size(); ++i){
        cout << moun[i] << ' ';
    }
    for (unsigned int i = 0; i <= mark; ++i){
        cout << moun[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
