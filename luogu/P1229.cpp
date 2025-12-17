// Mon Dec 15 07:32:02 PM CST 2025
// 前序是本左右, 后序是左右本, 中序是左本右, 当只有一个子节点时, 前序ab, 后序ba, 中序可以ab也可以ba
// 故我们找出只有一个子节点的节点, 1 << 节点数就可以了
// 怎么找?
// 当一个节点只有一个子节点, 他的前序遍历中肯定有父子, 他的后序遍历中肯定有子父
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 0;
    for (unsigned int i = 0; i < s1.size() - 1; ++i){
        // pre
        char root = s1[i];
        char chil = s1[i+1];
        // Back
        int root_b = s2.find(root);
        int chil_b = s2.find(chil);
        
        if (root_b - chil_b == 1){
            ans++;
        } 
    }
    cout << (1<<ans);
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
