// PreOrder
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
int n;
struct Node{
    char l = '*';
    char r = '*';
}tree[130];
void PreOrder(char root){
    if (root == '*') return;
    cout << root;
    PreOrder(tree[(int)root].l);
    PreOrder(tree[(int)root].r);
}
void solve() {
    cin >> n;
    char root, l, r;
    char Root = '*';
    for (int i = 0; i < n; ++i){
        cin >> root >> l >> r;
        if (i == 0) Root = root;
        tree[(int)root].l = l;
        tree[(int)root].r = r;
    }
    PreOrder((int)Root);

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
