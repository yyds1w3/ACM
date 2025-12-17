#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
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
auto get_id (int x, vector<int> &nums){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
};
struct query{
    int i, j, e;
};
void solve() {
    int n;
    cin >> n;
    vector<query> queries(n); // 大小为 n
    vector<int> nums;
    
    for (int k = 0; k < n; ++k){
        cin >> queries[k].i >> queries[k].j >> queries[k].e;
        nums.push_back(queries[k].i);
        nums.push_back(queries[k].j);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    int m = nums.size();
    DSU dsu(m); // 不需要 2*m
    sort(queries.begin(), queries.end(), [](const query &a, const query &b){
        return a.e > b.e; // e=1 排在 e=0 前面
    });
    
    for (auto &q : queries){
        int u = get_id(q.i, nums);
        int v = get_id(q.j, nums);
        
        if (q.e == 1) {
            dsu.merge(u, v); 
        } else {
            if (dsu.ask(u, v)) { 
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES\n"; 
 
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
    cin >> tt;
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
