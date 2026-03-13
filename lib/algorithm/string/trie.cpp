#include <bits/stdc++.h>

constexpr int N = 1e6 + 10; // 最多的字母个数

int trie[N][26]; // trie[i][0] 表示第i个节点通过'a'去的下一个节点编号 描述了节点之间的路径
int tot; // 分配的总节点
int pass[N], end[N];
void init() {
    tot = 0;
}
int newNode() {
    tot++;
    std::fill(trie[tot], trie[tot] + 26, 0);
    pass[tot] = end[tot] = 0;
    return tot;
}
void insert(std::string& s) {
    int p = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[p][x] == 0) {
            trie[p][x] = newNode();
        }
        p = trie[p][x];
        pass[p]++;
    }
    end[p]++;
}
// 以S为前缀的数量
int query(std::string& s) {
    int p = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[p][x] == 0) {
            return 0;
        }
        p = trie[p][x];
    }
    return pass[p];
}
// 完整S的数量
int countWord(std::string& s) {
    int p = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[p][x] == 0) {
            return 0;
        }
        p = trie[p][x];
    }
    return end[p];
}

