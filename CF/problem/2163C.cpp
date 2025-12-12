#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;
    
    // 读入数据，使用 vector 方便管理
    vector<int> a1(n), a2(n);
    for(int &x : a1) cin >> x;
    for(int &x : a2) cin >> x;

    // 1. 预处理前缀（第一行）和后缀（第二行）的最值
    // prefMin[i] 表示 a1[0...i] 的最小值
    vector<int> prefMin(n), prefMax(n);
    prefMin[0] = a1[0]; prefMax[0] = a1[0];
    for(int i = 1; i < n; i++) {
        prefMin[i] = min(prefMin[i-1], a1[i]);
        prefMax[i] = max(prefMax[i-1], a1[i]);
    }

    // suffMin[i] 表示 a2[i...n-1] 的最小值
    vector<int> suffMin(n), suffMax(n);
    suffMin[n-1] = a2[n-1]; suffMax[n-1] = a2[n-1];
    for(int i = n - 2; i >= 0; i--) {
        suffMin[i] = min(suffMin[i+1], a2[i]);
        suffMax[i] = max(suffMax[i+1], a2[i]);
    }

    // 2. 将 N 条路径的属性 (v_k, u_k) 映射到数轴上
    // limit[v] 表示：若路径的最小值为 v，则该路径的最大值 u 至少是多少
    // 初始化为无穷大
    int max_val = 2 * n;
    vector<int> min_required_u(max_val + 2, 1e9);

    for(int k = 0; k < n; k++) {
        // 对于转折点 k 的路径：
        int path_min = min(prefMin[k], suffMin[k]);
        int path_max = max(prefMax[k], suffMax[k]);
        
        // 记录：只要 l <= path_min，我们就有可能通过这条路径，只要 r >= path_max
        // 我们先记录在 path_min 这个位置上
        min_required_u[path_min] = min(min_required_u[path_min], path_max);
    }

    // 3. 后缀最小值优化 (Suffix Min)
    // 如果 l 取 i 可以用某条路径，那 l 取 i-1 更可以用这条路径
    // 我们需要的是：对于给定的 l，所有满足 v_k >= l 的路径中，最小的 u_k 是多少
    for(int i = max_val; i >= 1; i--) {
        min_required_u[i] = min(min_required_u[i], min_required_u[i+1]);
    }

    // 4. 统计答案
    ll ans = 0;
    for(int l = 1; l <= max_val; l++) {
        // 对于当前的 l，允许的最小 r 是 min_required_u[l]
        if(min_required_u[l] <= max_val) {
            // r 的范围是 [min_u, 2n]
            ans += (max_val - min_required_u[l] + 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}