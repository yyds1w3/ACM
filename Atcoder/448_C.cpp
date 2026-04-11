#include <bits/stdc++.h>
#include <vector>
using ll = long long;
using i128 = __int128;
#define nl "\n"
struct Info {
    int val, id;
    bool operator<(const Info& other) {return val < other.val;}
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, Q;
    std::cin >> N >> Q;
    std::vector<Info> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i].val;
        A[i].id = i;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < Q; ++i) {
        int K;
        std::cin >> K;
        std::vector<bool> vis(N);
        for (int j = 0; j < K; ++j) {
            int x;
            std::cin >> x;
            vis[x-1] = true;
        }
        for (int i = 0; i < N; ++i) {
            if (!vis[A[i].id]) {
                std::cout << A[i].val << nl;
                break;
            }
        }
    }
}
