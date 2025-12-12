/**
 * Algorithm: Topological Sort (Kahn's Alogorithm) determined if DAG
 * Verified: Luogu P3644
 * Complexity: O(N + M)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

//============================start======================================
struct TopoSort{
    int n;
    vector<vector<int>> adj;
    vector<int> in_degree;
    vector<int> order;

    void init(int _n){
        n = _n;
        adj.assign(n+1, vector<int>());
        in_degree.assign(n+1, 0);
        order.clear();
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        in_degree[v]++;
    }
    bool solve(){
        queue<int> q; // 无前置任务的任务
        for (int i = 1; i <= n; ++i){
            if (in_degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adj[u]){
                in_degree[v]--;
                if (in_degree[v] == 0){
                    q.push(v);
                }
            }
        }
        return order.size() == n;
    }
}topo;

// ============================End=================================

int main(){
    IOS;
    int n,a;
    cin >> n;
    topo.init(n);
    for (int i = 1; i <= n; ++i){
        while(cin >> a){
            if (a == 0) break;
            topo.add_edge(i, a);
        }
    }
    if (topo.solve()){
        for (int v : topo.order){
            cout << v << ' ';
        }
    }


}