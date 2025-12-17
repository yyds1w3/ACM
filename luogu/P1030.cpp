#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
void PreOrder(string InString, string BackString){
    if (BackString.empty()) return;
    char root = BackString.back();
    cout << root;
    int root_pos = InString.find(root);
    // [0,k-1] [k] [k, n] Instring
    // [0,k-1] [k, n-1] [n] BackString
    PreOrder(InString.substr(0, root_pos), BackString.substr(0, root_pos));
    PreOrder(InString.substr(root_pos + 1), BackString.substr(root_pos, BackString.size()-root_pos-1));
}
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    PreOrder(s1, s2);
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
