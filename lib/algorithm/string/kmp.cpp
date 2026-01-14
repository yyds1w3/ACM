/**
 * Algorthim: KMP (0-based)
 * Verified: CF 126B
 * Complexity: O(N + M)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// =============start===============
const int MAXN = 1e5 + 1;
int nxt[MAXN];
string s;
string p;
void init() {
    nxt[0] = 0;
    int m = p.size();
    for (int i = 1, j = 0; i < m; ++i) { // i-->当前匹配字符串, j-->当前最长相同前后缀长度
        while (j > 0 && p[i] != p[j]) j = nxt[j - 1];
        if (p[i] == p[j]) j++;
        nxt[i] = j;
    }
}
void match() {
    int n = s.size();
    int m = p.size();
    for (int i = 0, j = 0; i < n; ++i) { // i-->s的当前字符指针位置, j-->p的当前字符指针
        while (j > 0 && s[i] != p[j]) j = nxt[j-1];
        if (s[i] == p[j]) j++;
        if (j == m) {
            cout << "Found: " << i - m + 1 << "\n";
            j = nxt[j-1];
        }
    }
}
