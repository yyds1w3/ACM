#include <bits/stdc++.h>
#include <vector>

std::vector<int> nxtArray(std::string &s) {
    int n = s.size();
    std::vector<int> nxt(n + 1); // nxt[i] == [0, i) 的最长公共前后缀
    // i 表示当前匹配字符下标， j 表示[0, i+1) 的最长公共前后缀的长度
    for (int i = 1, j = 0; i < n; ++i) {
        while (j && s[i] != s[j]) {
            j = nxt[j];
        }
        j += (s[i] == s[j]);
        nxt[i + 1] = j;
    }
    return nxt;
}
std::vector<int> kmpSearch(std::string s1, std::string s2) {
    if (s1.empty() || s2.empty() || s2.size() > s1.size()) return {};
    std::vector<int> res;
    std::vector<int> nxt = nxtArray(s2);
    int n = s1.size();
    int m = s2.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j && s1[i] != s2[j]) {
            j = nxt[j];
        }
        j += (s1[i] == s2[j]);
        if (j == m) {
            res.push_back(i - m + 1);
            j = nxt[j];
        }
    }
    return res;
}

