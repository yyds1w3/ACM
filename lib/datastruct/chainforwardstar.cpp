/**
 * Algorthim: ChainForwardStar
 * Verified: CF: 1551B2
 * Complexity: O(n)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ====================start===============================
const int MAXN = 1e5 + 1;
int head[MAXN], val[MAXN], nxt[MAXN];
int tot;
int n;
void init() {
    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
    }
    tot = 0;
}
void insert(int id, int v) {
    val[++tot] = v;
    nxt[tot] = head[id];
    head[id] = tot;
}

// ===================End=====================================
