#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    map<string, vector<int>> mp;
    for (int i = 1; i <= n; ++i){
        int l;
        string s;
        cin >> l;
        for (int j = 1; j <= l; ++j){
            cin >> s;
            if (mp[s].empty() || mp[s].back() != i)
            mp[s].push_back(i);
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        string s;
        cin >> s;
        for (int t : mp[s]){
            cout << t << " ";
        }
        cout << "\n";
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
