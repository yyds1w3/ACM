#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
vector<int> path;
void dfs(int rm, int lv){
    if (rm == 0){
        if (path.size() > 1){
            for (unsigned int i = 0; i < path.size(); ++i){
                cout << path[i] << (i == path.size() - 1 ? "" : "+"); 
            }
        }
        cout << '\n';
        return;
    } 
    for (int i = lv; i <= rm; ++i){
        path.push_back(i);
        dfs(rm-i, i);
        path.pop_back();
    }
}
void solve() {
    int n;
    cin >> n;
    dfs(n, 1);
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
