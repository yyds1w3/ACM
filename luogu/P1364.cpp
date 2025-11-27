#include <bits/stdc++.h>
using namespace std;

struct Node {
    int w, u, v;
};

const int N = 10010;
Node tree[N];
vector<int> E[N];
int sub[N], f[N], n; // sub每个节点的子树人口 f以u为根的加权距离和
int total;

// 从下至上求以u为根的f， 求出所有sub
void dfs1(int u, int fa) {
    sub[u] = tree[u].w;
    f[u] = 0;
    for(int v : E[u]) { // u的左右节点
        if(v == fa) continue;
        dfs1(v, u); // dfs子节点
        sub[u] += sub[v]; // 回溯更新sub
        f[u] += f[v] + sub[v]; // 子树加权距离
    }
}
// 从上至下求出任意u的f
void dfs2(int u, int fa) {
    for(int v : E[u]) {
        if(v == fa) continue;
        f[v] = f[u] - sub[v] + (total - sub[v]); // 从u->v, f的变化, v的子树少走, 非v的子树多走
        dfs2(v, u); // 递归
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        int w,u,v;
        cin >> w >> u >> v;
        tree[i] = {w,u,v};
        if(u) { E[i].push_back(u); E[u].push_back(i);}
        if(v) { E[i].push_back(v); E[v].push_back(i);}
    }

    dfs1(1, 0); // 求出sub
    total = sub[1]; // 根节点的子树人口就是total
    dfs2(1,0); // 求出f

    int ans_node = 1;
    int ans_val = f[1];
    for(int i=2;i<=n;i++){
        if(f[i] < ans_val){
            ans_val = f[i];
            ans_node = i;
        }
    }

    cout << ans_val << endl;
    return 0;
}
