/**
 * Algorthim: Hash
 * Verified: Luogu P3370
 * Complexity: Init O(N), Query O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
// ================Start=========================
const int P = 131;
// 字符串的整串hash
set<ull> st;
ull get_hash(string s) {
    ull res = 0;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) res = res * P + s[i];
    return res;
}
// 字符串的区间hash
const int MAXN = 1e5 + 1; // 字符串长度
ull h[MAXN], p[MAXN]; 
void init(string s) {
    int sz = s.size();
    p[0] = 1;
    h[0] = 0;
    for (int i = 0; i < sz; ++i) {
        p[i + 1] = p[i] * P; // p[1] = p, p[2] = p^2
        h[i + 1] = h[i] * P + s[i]; // h[1] = s[0], h[2] = s[0] * p + s[1]
    }
}
ull get_hash(int l, int r) { // 1-based ==> l = 2, r = 4 ==> 1234 ==> 234
    return h[r] - h[l - 1] * p[r - l + 1]; // 1234 - 1 * p[3] = 234
}
bool is_equal(int l1, int r1, int l2, int r2) {
    return get_hash(l1, r1) == get_hash(l2, r2);
}

// ===============End============================
