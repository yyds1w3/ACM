/**
 * Algorthim: DSU (Disjoint Set Union)
 * Verified: Luogu P3367
 * Complexity: O(N) but nearly ==> O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ================ start=====================
struct DSU{
    vector<int> fa, sz;
    DSU(int n){
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if (rx != ry){
            fa[rx] = ry;
            sz[ry] += sz[rx];
        }
    }

    bool ask(int x, int y){
        return find(x) == find(y);
    }

    bool size(int x){
        return sz[find(x)];
    }
};
// ========================End=======================

int main(){
    IOS;
    int n, m, x, y, z;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; ++i){
        cin >> z >> x >> y;
        if (z == 1){
            dsu.merge(x, y);
        }else if (z == 2){
            dsu.ask(x, y) ? cout << "Y" : cout << "N";
            cout << '\n';
        }
    }
}
