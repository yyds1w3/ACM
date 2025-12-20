// route 拓扑遍历的点数 < n
// mult 入度为0的点同时存在多个, q.size() > 1
// 记下矛盾点, 最后输出
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int n, m;
const int MAXN = 30;
vector<int> adj[MAXN];
int in[MAXN];
int temp_in[MAXN];
int topo(string &res){
    res = "";
    int cnt = 0;
    queue<int> q;
    bool multi_in = 0;
    for (int i = 0; i < n; ++i){
        temp_in[i] = in[i];
        if (!temp_in[i])
            q.push(i);
    }
    while (!q.empty()){
        if (q.size() > 1) multi_in = 1;
        int u = q.front();
        q.pop();
        res += (char)u + 'A';
        cnt++;
        for (int v : adj[u]){
            temp_in[v]--;
            if (!temp_in[v]) q.push(v);
        }
    }
    if (cnt < n) return 2; // route
    if (multi_in) return 0; // multi point when indegree == 1
    return 1;
}
void solve() {
    cin >> n >> m;
    int type = 0; // 0 寻找中 1 确定 2 矛盾
    int step = 0;
    string final_res = "";
    for (int i = 0; i < m; ++i){
        char a, b, c;
        cin >> a >> b >> c;
        if (type != 0) continue;
        adj[a - 'A'].push_back(c - 'A');
        in[c - 'A']++;

        string res;
        int state = topo(res);
        if (state == 1){
            type = 1;
            step = i+1;
            final_res = res;
        }else if(state == 2){
            type = 2;
            step = i+1;
        }
    }
    if (type == 1) 
        cout << "Sorted sequence determined after " << step << " relations: " << final_res << "." << endl;
    else if (type == 2) 
        cout << "Inconsistency found after " << step << " relations." << endl;
    else 
        cout << "Sorted sequence cannot be determined." << endl;
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
