#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(x) 42
#endif
const int N = 2e5+1;
int pre[N];
void solve() {
    string s;
    cin >> s;
    for (unsigned int i = 0; i < s.size(); ++i){
        if (s[i] == s[i+1]){
            pre[i+1] = pre[i] + 1;
        }else pre[i+1] = pre[i];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int l, r;
        cin >> l >> r;
        cout << pre[r-1] - pre[l-1] << '\n';
    }
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
    // cin >> tt;
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
