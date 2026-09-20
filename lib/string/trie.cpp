#include <bits/stdc++.h>

constexpr int N = 1e6 + 10;

int trie[N][26];
int tot;
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
    int cur = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[cur][x] == 0) {
            trie[cur][x] = newNode();
        }
        cur = trie[cur][x];
        pass[cur]++;
    }
    end[cur]++;
}
// 以S为前缀的数量
int query(std::string& s) {
    int cur = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[cur][x] == 0) {
            return 0;
        }
        cur = trie[cur][x];
    }
    return pass[cur];
}
// 完整S的数量
int countWord(std::string& s) {
    int cur = 0;
    int l = s.size();
    for (int i = 0; i < l; ++i) {
        int x = s[i] - 'a';
        if (trie[cur][x] == 0) {
            return 0;
        }
        cur = trie[cur][x];
    }
    return end[cur];
}

