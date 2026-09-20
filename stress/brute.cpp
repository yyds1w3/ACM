// ============================================================
// 对拍用暴力 —— 唯一的要求：显然正确。不要求效率。
// 它只在 n <= 8 的小数据上跑，所以多烂的复杂度都行。
//
// 骨架是固定的，你只需要填三个洞：
//   洞 1  State 是什么
//   洞 2  goal(状态)   —— 题面里「什么算达成」的逐字翻译
//   洞 3  nexts(状态)  —— 题面里「一次操作能干什么」的逐字翻译
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ---- 洞 1：状态 ---------------------------------------------------
// 常见：string / vector<int> / pair<int,int> / 自定义 struct(要定义 <)
using State = string;

// ---- 洞 2：什么算成功 ---------------------------------------------
// 逐字翻译题面，不要在这里做任何优化。
// 2085A 的填法： r < reverse(r)
bool goal(const State& cur) {
    return false;                       // ← 填这里
}

// ---- 洞 3：一步操作能到达的所有状态 -------------------------------
// 题面说「一次能做什么」，就全部生成出来，别管有多少个。
// 2085A 的填法：swap 任意两个下标
vector<State> nexts(const State& cur) {
    vector<State> res;
    // int n = cur.size();
    // for (int i = 0; i < n; i++)
    //     for (int j = i; j < n; j++) {
    //         State nx = cur;
    //         swap(nx[i], nx[j]);
    //         res.push_back(nx);
    //     }
    return res;                         // ← 填这里
}

// ================================================================
// 从这里到 main 之间不用改：
// BFS 枚举「不超过 k 步」能到达的所有状态
// ================================================================
bool brute(const State& start, int k) {
    set<State> vis{start};
    queue<pair<State, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
        auto [cur, d] = q.front();
        q.pop();
        if (goal(cur)) return true;     // 到了就赢
        if (d == k) continue;           // 步数用完
        for (const State& nx : nexts(cur))
            if (vis.insert(nx).second) q.push({nx, d + 1});
    }
    return false;
}
// 骨架的变体（换题时挑一个）：
//   要输出「最少几步」    → 把 bool 换成 int，BFS 里直接 return d
//   要枚举子集            → for (int mask = 0; mask < (1 << n); mask++)
//   要枚举排列            → do { ... } while (next_permutation(...))
//   步数很多 / 是构造题   → BFS 换 DFS + 回溯，把 depth 限制住
//   输出是一串操作        → 不写暴力，写 checker（验证输出是否合法）

int main() {
    // 输入输出按题面改。多数题是 t 组。
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        State s;
        int k;
        cin >> s >> k;                                      // ← 按题面改
        cout << (brute(s, k) ? "YES" : "NO") << "\n";       // ← 按题面改
    }
}
