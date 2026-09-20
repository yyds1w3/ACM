#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> f(N+1); // 最长真公共前后缀(不可包含全部)
std::vector<int> f2(N+1); // 最短假公共前后缀(首尾不同时包含全部)
void kmp(std::string s) {
    int n = s.size();
    f.assign(n + 1, 0);
    f2.assign(n+1, 0);
    f2[1] = 1;
    for (int i = 1, j = 0; i < n; ++i) {
        while (s[i] != s[j] && j) {
            j = f[j];
        }
        if (s[i] == s[j]) j++;
        f[i + 1] = j;
        f2[i+1] = (f[i+1] == 0 ? i + 1 : f2[f[i+1]]);
    }
}
