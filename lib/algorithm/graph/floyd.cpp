/**
 * Algorthim: Floyd 
 * Verified: CF 295B
 * Complexity: O(N^3)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ====================Start=======================
const int MAXN = 505;
const ll INF = 1e18;
ll dist[MAXN][MAXN];
int n, m;
void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][k] +  dist[k][j] , dist[i][j]);
            }
        }
    }
}
