#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, q;
    std::cin >> n >> q;
    std::vector<int> point(n + 1, 0); // 指向状态
    std::vector<int> parent(1, 0); // parent[v] ==> v状态的上一个状态
    std::vector<std::string> str(1, ""); // str[v] ==> v状态新增字符串
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p;
            std::cin >> p;
            point[p] = point[0];
        }else if (op == 3) {
            int p;
            std::cin >> p;
            point[0] = point[p];
        }else if (op == 2) {
            int p;
            std::string s;
            std::cin >> p >> s;
            int sz = parent.size();
            parent.push_back(point[p]);
            str.push_back(s);
            point[p] = sz;
        }
    }
    int curr = point[0];
    std::vector<std::string> ans;
    while (curr != 0) {
        ans.push_back(str[curr]);
        curr = parent[curr];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i];
    }
    std::cout << nl;
}
