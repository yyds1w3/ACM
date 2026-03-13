#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
const int MAXN = 2e5 + 1; // 字符串的个数
const int MAXS = 2e6 + 1; // 字符的个数
int tree[MAXS][26], tot; // 字典树（直通表） tree[2][0] 表示 节点2通过'a'的下一个节点
int end[MAXN], freq[MAXS], fail[MAXS]; // end[i]表示第i个目标字符串的结尾节点， freq[i]表示第i个节点的词频统计， fail[i]表示i匹配失败后应该去的节点编号（最长后缀）


void insert(int i, std::string s) {
    int u = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
        int x =  s[j] - 'a';
        if (tree[u][x] == 0) {
            tree[u][x] = ++tot;
        }
        u = tree[u][x];
    }
    end[i] = u;
}
void setFail() {
    std::queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (tree[0][i] != 0) {
            q.push(tree[0][i]);
        } 
    }
    // 深度为1的节点不用设置fail指针， 应该为0
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 26; ++i) {
            if (tree[u][i] == 0) { // 匹配失败就修改到u的fail指针, 优化后就是修改u的直通表
                tree[u][i] = tree[fail[u]][i];
            }else { // 匹配成功就修改孩子的fail指针, 并且把孩子压入队列
                fail[tree[u][i]] = tree[fail[u]][i];
                q.push(tree[u][i]);
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string t;
        std::cin >> t;
        insert(i, t);
    }
    setFail();
    std::string s;
    std::cin >> s;
    for (int i = 0, u = 0; i < (int)s.size(); ++i) { // 此处只统计了fail --> fail --> u  的u的词频
        u = tree[u][s[i] - 'a'];
        freq[u]++;
    }
    std::vector<std::vector<int>> adj(tot + 1); // 0 - tot, 关于fail指针的反向图
    for (int i = 1; i <= tot; ++i) {
        adj[fail[i]].push_back(i);
    }
    auto dfs = [&] (auto self, int u) -> void {
        for (int v : adj[u]) {
            self(self, v);
            freq[u] += freq[v];
        }
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i) {
        std::cout << freq[end[i]] << nl;
    }
}

