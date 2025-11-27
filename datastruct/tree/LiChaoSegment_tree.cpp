#include <cmath>

const int M = 1e6 + 1; // 叶子数量 
const int N = 4 * M;   // 存线段树
// 这里提供两种线段树写法: 1.存区间和 2. 存差分
// 前者求区间和有用， 后者对区间修改有用
// 下标均从1开始

// -------1-----------------

int A[M], B[N]; 

// build
void build(int s, int t, int p){
    if (s == t){
        B[p] = A[s];
        return;
    }
    int m = s + ((t - s) >> 1); // 中点
    build(s, m, 2 * p);
    build(m+1, t, 2 * p + 1);
    // 回溯填值
    B[p] = B[p*2] + B[p*2+1];
}

// query
int query(int s, int t){
    int ans = 0;
    if (s == 1) {ans += A[1]; s++;}
    if (t == M) {ans += A[M]; t--;}
    s += M - 1; // 注意这里的M代指叶子结点数，并不是真的M嗯对
    t += M + 1;
    while (s ^ t ^ 1){ // 非兄弟节点(即是第二层)
        if (~s & 1) ans += B[s ^ 1]; // 是左孩子就加右孩子
        if (t & 1)  ans += B[t ^ 1]; // 是右孩子就加左孩子
        s >>= 1, t >>= 1;
    }
    return ans;
}

// change
void change(int index, int value){
    A[index] = value;
    index += M;
    B[index] = value;
    while (index > 1){
        index >>= 1;
        B[index] = B[index * 2] + B[index * 2 + 1];
    }
}

// -------2---------  不存区间信息，只存差分值  ---------
// 重点: 真实值 = T[x] + T[x>>1] + T[x>>2] + ... + T[1]

int T[N]; // 差分树，注意不存区间值

// 叶子构造：T[i+M] = A[i] - A[i-1]
// 父节点的值不重要，之后会动态修正
void build(){
    for (int i = 1; i <= M; i++){
        T[i + M] = A[i] - A[i - 1]; // 相邻差分
    }
    // 这里不用像普通线段树一样 pushUp 求区间信息
    // 直接填满叶节点，上面的先没管
}

// 对区间 [s, t] 每个值 + value
// 逻辑：只操作差分值，不改叶子真实值
void add(int s, int t, int value){
    s += M - 1;
    t += M + 1;

    while (s ^ t ^ 1){
        if (~s & 1) T[s ^ 1] += value; // 左孩子，给右兄弟加
        if (t & 1)  T[t ^ 1] += value; // 右孩子，给左兄弟加

        int A = std::min(T[s], T[s^1]);
        T[s] -= A, T[s^1] -= A, T[s >> 1] += A;

        int B = std::min(T[t], T[t^1]);
        T[t] -= B, T[t^1] -= B, T[t >> 1] += B;

        s >>= 1; t >>= 1;
    }
}

