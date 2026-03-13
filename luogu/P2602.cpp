#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
i64 dp[13][14]; // dp 表示的是 在pos之前已经选了cnt个目标数字， 求之后的数位的选择的数字个数的总和
std::string s;
// lead == 1 // 前面位都是0
// limit == 1 // 这个位不能乱填
i64 dfs(int pos, int cnt, int lead, int limit, int d) {
    if (pos == s.size()) {
        return cnt;
    } 
    if (!lead && !limit && dp[pos][cnt] != -1) {
        return dp[pos][cnt];
    } 
    i64 res = 0;
    int up = limit ? s[pos] - '0' : 9;
    for (int i = 0; i <= up; ++i) {
        res += dfs(pos + 1, cnt + (i == d && !(lead && i == 0)), lead && (i == 0), limit && (i == up) , d);
    }
    if (!lead && !limit) dp[pos][cnt] = res;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 a, b;
    std::cin >> a >> b;
    for (int d = 0; d < 10 ; ++d) {
        memset(dp, -1, sizeof(dp));
        s = std::to_string(b);
        i64 cntb = dfs(0, 0, 1, 1, d);
        memset(dp, -1, sizeof(dp));
        s = std::to_string(a - 1);
        i64 cnta = dfs(0, 0, 1, 1, d);
        std::cout << cntb - cnta << " ";
    } 

}
