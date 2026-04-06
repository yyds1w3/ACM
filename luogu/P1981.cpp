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
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> stk;
    int num = 0;
    char op = '+';
    for (int i = 0; i <= n; ++i) {
        if (std::isdigit(s[i])) {
            num = (num * 10 + s[i] - '0') % 10000; 
        }else {
            if (op == '+') {
                stk.push_back(num);
            }
            else if (op == '*') {
                stk.back() = (stk.back() * num) % 10000;
            }
            if (s[i] == '+') {
                op = '+';
                num = 0;
            }else if (s[i] == '*') {
                op = '*';
                num = 0;
            }
        }
    }
    while (stk.size() > 1) {
        int x = stk.back();
        stk.pop_back();
        stk.back() = (x + stk.back()) % 10000;
    }
    std::cout << stk.back() << nl;
}
