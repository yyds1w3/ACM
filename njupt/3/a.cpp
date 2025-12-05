#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 500005;
const int M = 4005; // 操作数上限

// 数组 a 存储当前环境值，必须开 long long 防止溢出
ll a[N];
int n, m;

// 用于记录单次修改的细节：哪个位置，修改前的值是多少
struct Change {
    int idx;
    ll old_val;
};

// history[op_id] 记录第 op_id 次操作具体改了哪些值
// 注意：这里的下标对应的是真实的“操作计数”，而不是题目的时间 t
vector<Change> history[M];

// 记录当前“生效”的操作编号序列
vector<int> active_ops;

// EndState[t] 记录第 t 刻结束时，active_ops 的大小
// 这样当我们想回到 t 刻时，就知道栈里应该保留多少个操作
int EndState[M];

int main() {
    // 优化 IO
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // op_cnt 用于给每一个“修改操作”分配唯一的 ID
    int op_cnt = 0;

    // t 代表题目中的“当前时刻”，从 1 开始流逝到 m
    for (int t = 1; t <= m; ++t) {
        int c;
        cin >> c;

        if (c == 1) { // 神灵发动法术（修改）
            int l, r;
            cin >> l >> r;
            
            op_cnt++; // 分配一个新的操作 ID
            
            // 执行修改并记录历史
            for (int i = l; i <= r; ++i) {
                // 1. 记录旧值以便撤销
                history[op_cnt].push_back({i, a[i]});
                // 2. 执行修改：注意题目公式里的 t 是当前时刻
                a[i] += (ll)(i - l + 1) * t;
            }
            
            // 将这个操作标记为“生效中”
            active_ops.push_back(op_cnt);
            // 记录时刻 t 的状态快照
            EndState[t] = active_ops.size();

        } else if (c == 2) { // 时空折叠（回溯）
            int target_t;
            cin >> target_t;
            
            // 我们要回到 target_t 刻结束时的状态
            // 目标是让 active_ops 的大小变回 EndState[target_t]
            int target_size = EndState[target_t];
            
            // 不断撤销栈顶操作，直到达到目标状态
            while (active_ops.size() > target_size) {
                int op_to_undo = active_ops.back();
                active_ops.pop_back();
                
                // 撤销该操作的所有修改（逆序恢复更安全，虽然这里是点修改无所谓）
                // vector.rbegin() 和 rend() 用于反向遍历
                for (auto it = history[op_to_undo].rbegin(); it != history[op_to_undo].rend(); ++it) {
                    a[it->idx] = it->old_val;
                }
                
                // 注意：history[op_to_undo] 不需要清空，因为这个操作ID以后不会再被用了
                // 新的操作会申请新的 op_cnt
            }
            
            // 当前时刻 t 的状态 = 目标时刻的状态
            EndState[t] = target_size;

        } else { // 空的询问
            int l, r;
            cin >> l >> r;
            
            ll ans = 0;
            for (int i = l; i <= r; ++i) {
                if (a[i] % 2 != 0) { // 判断奇数
                    ans += a[i];
                }
            }
            cout << ans << "\n";
            
            // 查询不改变状态，直接继承上一刻的状态
            EndState[t] = active_ops.size();
        }
    }

    return 0;
}