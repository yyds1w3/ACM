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
const int MAXN = 1e6 + 1;
int heap[MAXN], sz ;
void up(int k) {
    while (heap[k] < heap[k >> 1]) {
        swap(heap[k], heap[k >> 1]);
        k >>= 1;
    }
}
void down(int k) {
    while ((k << 1) <= sz) {
        int t = k << 1;;
        if (t + 1 <= sz && heap[t+1] < heap[t]) t++;
        if (heap[t] >= heap[k]) break;
        swap(heap[t], heap[k]);
        k = t;
    }
}
void add(int x){
    heap[++sz] = x;
    up(sz);
}
int top() {
    return heap[1];
}
void pop() {
    swap(heap[1], heap[sz]);
    sz--;
    down(1);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        int op, x;
        cin >> op;
        if (op == 1){
            cin >> x;
            add(x);
        }else if (op == 2) {
            cout << top() << "\n";
        }else {
            pop();
        }
    }
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
