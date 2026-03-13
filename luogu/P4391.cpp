#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int L;
    std::cin >> L;
    std::string s1;
    std::cin >> s1;
    std::vector<int> nxt(L + 1);
    for (int i = 1, j = 0; i < L; ++i) {
        while (j && s1[i] != s1[j]) {
            j = nxt[j];
        }
        j += (s1[i] == s1[j]);
        nxt[i + 1] = j;
    }
    std::cout << L - nxt[L] << nl;
}
