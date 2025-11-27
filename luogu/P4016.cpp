#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> A[N];
int D[N], n, c;
void dfs(int u, int fa){ // 当前结点, 父节点
    for (int v : A[u]){
        if (v == fa) continue; // 防止回到父节点打转转(树没有连通, 只要不走回头路都可以)
        D[v] = D[u] + 1; // 更新下一个结点距离
        if (D[v] > D[c]) c = v; // c是距离起始点最远的点
        dfs(v, u); // 下一个结点继续dfs
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs(1, 0); // 随便一个点
    D[c] = 0;
    dfs(c, 0);
    cout << D[c];
}

