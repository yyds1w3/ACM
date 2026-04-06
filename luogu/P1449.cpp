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
    int num = 0;
    std::vector<int> stk(n);
    int top = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (std::isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }else if (s[i] == '.') {
            stk[++top] = num;
            num = 0;
        }else if (s[i] == '+') {
            int x = stk[top--];
            int y = stk[top--];
            stk[++top] = x + y;
        }else if (s[i] == '-') {
            int x = stk[top--];
            int y = stk[top--];
            stk[++top] = y - x;
        }else if (s[i] == '*') {
            int x = stk[top--];
            int y = stk[top--];
            stk[++top] = x * y;
        }else if (s[i] == '/') {
            int x = stk[top--];
            int y = stk[top--];
            stk[++top] = y / x;
        }
    }
    std::cout << stk[top] << nl;
}
