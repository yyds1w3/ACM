//Mon Sep 14 05:23:36 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
bool isPrime(int x) {
    if (x <= 3) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::string ans(n, ' ');
    std::map<char, char> mp;
    std::vector<bool> use(10); 
    auto dfs = [&](auto self, int idx) -> void {
        if (idx == n) {
            int x = std::stoi(ans);
            if (isPrime(x)) {
                std::cout << x << nl;
                exit(0);
            }
            return;
        }
        int down = (idx == 0 ? 1 : 0);
        if (mp.count(s[idx]) != 0) {
            ans[idx] = mp[s[idx]];
            self(self, idx + 1);
        }else {
            for (int i = down; i <= 9; ++i) {
                if (!use[i]) {
                    use[i] = true;
                    mp[s[idx]] = char('0' + i);
                    ans[idx] = char('0' + i);
                    self(self, idx + 1);
                    use[i] = false;
                }
            }
            mp.erase(s[idx]);
        }
    };
    dfs(dfs, 0);
    std::cout << -1 << nl;
}
