#include <bits/stdc++.h>
#define nl "\n"

using i64 = long long;

struct Node {
    i64 need;   // 完成这一段至少需要多少初始资金
    i64 gain;   // 完成这一段之后净增加多少资金
    int i;      // 楼
    int r;      // 完成到第 r 层

    bool operator<(const Node& other) const {
        return need > other.need;
    }
};

void solve() {
    int n;
    i64 x;
    std::cin >> n >> x;

    std::vector<int> h(n + 1, 0);
    std::vector<std::vector<i64>> a(n + 1);
    std::vector<std::vector<i64>> b(n + 1);

    for (int i = 1; i <= n; ++i) {
        int m;
        std::cin >> m;

        a[i].resize(m + 1);
        b[i].resize(m + 1);

        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j];

        for (int j = 1; j <= m; ++j)
            std::cin >> b[i][j];
    }

    std::priority_queue<Node> pq;

    // 从第 l 层开始，找到最短的“总收益 >= 0”的连续段
    auto get_segment = [&](int i, int l) -> Node {
        int m = (int)a[i].size() - 1;

        if (l > m)
            return {-1, -1, i, -1};

        i64 loss = 0;
        i64 need = 0;

        for (int r = l; r <= m; ++r) {
            // 前面已经累计亏损 loss，
            // 现在建第 r 层需要 loss + a[i][r]
            need = std::max(need, loss + a[i][r]);

            // 净亏损增加
            loss += a[i][r] - b[i][r];

            // 总收益 >= 0
            if (loss <= 0) {
                return {
                    need,
                    -loss,
                    i,
                    r
                };
            }
        }

        return {-1, -1, i, -1};
    };

    // 每栋楼的第一段
    for (int i = 1; i <= n; ++i) {
        Node cur = get_segment(i, 1);

        if (cur.r != -1)
            pq.push(cur);
    }

    /*
     * 先把所有能“回本”的段尽可能建掉。
     *
     * 每个段 gain >= 0，
     * 因此建完它之后资金不会下降。
     */
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (x < cur.need)
            break;

        x += cur.gain;
        h[cur.i] = cur.r;

        // 暴露这栋楼的下一段
        Node nxt = get_segment(cur.i, cur.r + 1);

        if (nxt.r != -1)
            pq.push(nxt);
    }

    /*
     * 此时 x 已经是“能够通过正收益段获得的最大资金”。
     *
     * 接下来如果想继续提高某栋楼，
     * 就只能把剩余资金全部投入这一栋楼。
     */
    int ans_h = 0;
    int ans_id = 1;

    for (int i = 1; i <= n; ++i) {
        i64 money = x;
        int cur_h = h[i];

        while (cur_h < (int)a[i].size() - 1) {
            int j = cur_h + 1;

            if (money < a[i][j])
                break;

            money -= a[i][j];
            money += b[i][j];

            ++cur_h;
        }

        if (cur_h > ans_h) {
            ans_h = cur_h;
            ans_id = i;
        }
        else if (cur_h == ans_h && i < ans_id) {
            ans_id = i;
        }
    }

    std::cout << ans_h << ' ' << ans_id << nl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
