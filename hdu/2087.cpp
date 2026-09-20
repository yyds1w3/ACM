//Fri Jul 24 02:35:47 PM CST 2026
#include <iostream>
#include <vector>
#include <string>
#define nl "\n"
using i64 = long long;
// i -> 主串索引
// j -> 模式串索引
// nxt[j] -> j匹配失败, j-1的跳转位置
int kmp(std::string &s1, std::string &s2) {
    int n = s1.size();
    int m = s2.size();

    std::vector<int> nxt(m + 1);
    // 后缀[1, m - 1]
    // 前缀[0, m - 2]
    for (int i = 1, j = 0; i < m; ++i) {
        while (j && s2[i] != s2[j]) {
            j = nxt[j];
        }
        j += (s2[i] == s2[j]);
        nxt[i + 1] = j;
    }
    
    int res = 0;
    for (int i = 0, j = 0; i < n; ++i){
        while (j && s1[i] != s2[j]) {
            j = nxt[j];
        }
        j += (s1[i] == s2[j]);
        if (j == m) {
            j = 0;
            res++;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s1, s2;
    while (true) {
        std::cin >> s1;
        if (s1 == "#") break;
        std::cin >> s2;
        std::cout << kmp(s1, s2) << nl;
    }
}
