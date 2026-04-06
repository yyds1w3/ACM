## 数学

### 质数筛

> 任何一个合数都是可以整除比他小的一个质数

- **P5440** 要判断一个数是否是质数， 就要看$\sqrt{N}$的范围里的质数能不能整除
- **412_E** 区间筛法， 用小筛子去筛大数, 对于每个小质数， 乘以 倍数后把[L,R]里的合数筛掉,剩下的就一定是质数

### 矩阵加速

- 斐波那契 **POJ-3070** 
  $$
  \begin{pmatrix}
  F_n F_{n-1}
  \end{pmatrix}
  \begin{bmatrix}
  1&1\\
  1 &0\\
  \end{bmatrix}
  $$
  
- **POJ-3233** 

$$
\begin{pmatrix}
A_k&S_k
\end{pmatrix}
\begin{bmatrix}
A&A\\
0&1\\
\end{bmatrix}
=
\begin{pmatrix}
A_{k+1}&S_{k+1}
\end{pmatrix}
$$

- **P1306** $gcd(f_i, f_j) = f_{gcd(i, j)}$ 斐波那契数列最大公因数性质

### 斐蜀定理

> 两个互质的数a和b
>
> 凑不出的最大整数为$S = a * b - a - b$, 在S之后的数都可以用a 和 b凑出来（用于路径压缩）， 所以大于S的路径直接变成S长度

- 路径压缩 **P1052**

### 概率论

1. 逆元的计算（费马小定理（$n ^ {p-2}$ 前提是p是质数）， 扩展欧拉函数）： 适用于求单点的逆元

2. 逆元的预处理 （阶乘预处理， 再处理逆元） ： 适用于大范围的逆元

3. 模类Z

4. 组合数$C_n^m = \frac{n!(n-m)!}{m!}$

   

### 计算几何

#### 扫描线







## 动态规划

### DP数组的初始化

- 求方案数（初始化为-1）来看看是否算过
- 求最小值（初始化为1E9）
- 求最大值（初始化为-1E9）



### 线性DP



### 最长递增子序列

```cpp
tails数组 --> tails[1] = 7 代表长度为2的LIS的最小结尾数字为7
```





### 树上DP

> 套路： 父节点的**全集信息**需要靠子节点的**全集信息**递归来返回

- 例题

  - 树上背包
    - [P12136](https://www.luogu.com.cn/problem/P12136)
    - [P1273](https://www.luogu.com.cn/problem/P1273)
    - **P201
    
  - 树上DP
    - [P1352](https://www.luogu.com.cn/problem/P1352)
    - [P1122](https://www.luogu.com.cn/problem/P1122)
    - **P2607** 基环树"森林" --> 多个连通块，但每个连通块都只有一个基环树(一个环，环上的节点可以形成树)
    - **P3177** 树上染色 -- 边的贡献


### 数位DP

> 利用条件判断加递归

- 技巧
  - 利用转字符串来的到数字的某一位

- 例题
  - P2602

### 状压DP

> `dp[status][i]` status == (1 << MAXN)， 用位来表示每一个东西已经选了或者还没选(状态的子集状态)

- 例题
  - 旅行商问题 P1433 P1171 列举mask从小到大
  - 棋盘问题 P1896  P2704
  - 老鼠吃奶酪 P1433

### 0-1背包

> 两个变量: 容量和价值， 依次遍历每个物品，更新dp[容量] = std::max(价值1， 价值2)， dp[i]数组定义是在容量为x的时候最大价值是多少， 可以买或者不买来更新

- **410_E**

## 数据结构

### 链表

- **P1996**
- **P1160**

#### 带版本控制的链表(可持久化)

- **411_D**

### 前缀和

> 二维前缀和公式 : `a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]`
>
> 二维差分公式: `d[x1][y1]++, d[x1][y2 + 1]--, d[x2 + 1][y1]--, d[x2 + 1][y2 + 1]++`

- **410E** 二维前缀和

### BIT

> a[0011] 代表以3结尾，长度为1的区间和, a[0100]代表以4结尾，长度为4的区间和

维护可差分信息（由两个大区间得到一个小区间）

1. 单点修改 + 区间查询（维护原数组） **P3374**

2. 单点查询 + 区间修改（维护差分数组）**P3368**
3.  区间查询 + 区间修改 （维护D和Di）**P3372**
4. 二维数组 + 单点修改 + 区间查询 （维护二维数组）
5. 二维数组 + 区间修改 + 区间查询 （维护二维差分数组）**P4514**

### DSU

- **408_E** :求两点之间最小OR路径， 维护连通性
- **Bailian-1182** **P1525 **拓展域并查集
- **hdu3038** **hdu3635**带权并查集, 相对位置...
- **P4185** 并查集加离线海量查询

### RMQ

> 对数组的范围静态查询， （最大值， 最小值， 最大公约数）
>
> $$rmq[i][k]$$ 可以理解成管辖[i, i + (1 << k))的一个值

- 倍增思想： 就是很大的区间分成一个较大的区间，然后剩下的区间再递归... **P4155**



### 单调栈

> 找到阶段性的强者

- 例题
  - 动态后缀最大值 **P1198**
  - 求全0矩形的方案 **P1950**
  - 求最大全0矩形 **P4147**

### 单调队列/滑动窗口

> 与普通的队列不同的是，这是一个双端队列

- **P1886** 求一个窗口内的的最大值, 最小值
- **P1714** 求不定长子段最大和（前缀和 + 滑动窗口）
- **P3957** 二分答案 + [L, R]的单调队列 + 坐标离散
- **P1419** 二分答案 + [L, R]的单调队列 + 前缀和

### 堆/优先队列

> 自动维护最小值，最大值， 反悔贪心的关键数据结构

## 算法

### 搜索

> 每个节点都是状态(位置， 颜色......), 我们需要找到一条从起点到终点的有效边

- 暴力搜索 -> 剪枝叶(处理无效状态)
  - P5294
  - P1118  一维上的， 从左到右选数问题
  
- 暴力搜索 -> 开dp数组(处理重复问题)

- 折半搜索(用空间换时间), 先把前半部分的结果存起来(DFS)

  - 适用于一维上的选和不选求子集和, 然后$2^N会TLE但是2^{N/2}不会的数据范围$

  - 时间: $2^N\to2^{N/2}+2^{N/2}\times log(2^{N/2})$
  - 空间: $0 \to 2^{N/2}$
  - **P3067** 折半搜索 + 掩码（表示集合状态）+ vector排序去重替代set
  - **P4799**
  - **P5195** 两段BFS
  
- IDA*（带有深度限制的， 带有估价函数剪枝的DFS)

  - 适用范围是: 状态的分支太多会爆队列, 却要求最小步数

  - **POJ3134**

### 分治法

> 把大问题分成两半， 再递归合并

- **P1908** 分治求逆序对

### CDQ分治



### 图论

#### BFS

- 多源BFS  ABC_405_D

#### 洪水填充

- **P1162**
- **P1506**



#### 二分图

- 定理 : 二分图不存在奇环, 用染色法来判断是否是二分图(判断是否有奇环)[二分图染色](https://codeforces.com/contest/2204/problem/D)

- 二分图最大匹配（匈牙利算法）: 二分图中每条边都是一对一的（没有公共节点）**P3386**



#### 哈夫曼树

> 高频短码， 低频长码， 从底至上

- **P1090**
- **P2168** K分支哈夫曼树， 要挂空节点保证最后剩一个

### dji算法

> 优先队列维护的是**全局**的最近的点

- **P3956** 带颜色状态的Dij算法
- **P1126** 机器人搬货物，要判断合法状态

### 字符串

#### 马拉车

> 解决回文问题



#### KMP

> 找到S1中的S2的位置 , $S_2 \in S_1$
>
> $nxt$数组是在[0, i)的前缀中的最长公共前后缀
>
> $n-nxt[n] == x$ 则$s[i] == s[i+x]$ 则x为最小循环字串的大小



#### 字符串哈希

> 判断字符串是否相等

#### 字典树（前缀树）

> 记录多个字符串的前缀

1. 维护字符串的字典树
2. 0-1 Trie 求路径最大异或和 P4551

## 杂项

### 旋转操作

- 顺时针90° $(i, j) \to (j, N-1-i)$
- 逆时针90°$(i, j) \to (N-1-j,i)$

```cpp
// 顺时针
vector<string> ns(n);
for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < N; ++j) {
        ns[j] += s[i][j]; 
    }
}
// 从最后一行向上从左到右发牌
// 1 2 3       7 4 1
// 4 5 6 ====> 8 5 2
// 7 8 9       9 6 3

// 逆时针
vector<string> ns(n);
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        ns[N - 1 - j] += s[i][j];  
    }
}

// 
// 1 2 3      3 6 9
// 4 5 6 ===> 2 5 8
// 7 8 9      1 4 7
```

### 位运算

```cpp
// 取一位数n的最高位1的位置
int high_bit = 63 - __builtin_clzll(n);
// 制作一个数前i位都是1 (11111100000)
-(1 << i) + 1;
// 取一个数的最小的一位1
x & -x
// 取x的第i位
(x >> i) & 1
// 取反x的第i位
x ^= (1 << i)
// 将x的第i位取0
x &= ~(1 << i)
```

- **408E** 通过贪心求最小或和

### 贪心

#### 反悔贪心

> 在一维数组上进行要或者不要（这个值）， 带有前缀条件，用优先队列
>
> 先无脑入队列	

- 例题
  - [407_e](https://atcoder.jp/contests/abc407/tasks/abc407_e)
  - **P30



### 最大子段和

> Kadane 算法 ： 通过维护历史最值来判断是继续加，还是清零

- 普通的Kadane算法**P1719**
- 环形Kadane算法**P1121*

### 破环成链

- **P2629**
- **P4155** 断环成链后， 寻找覆盖区间超过环的连续区间就OK了

### 如何调代码

```cpp
#include <bits/stdc++.h>
#define _CLR_CYAN   "\033[1;36m"
#define _CLR_GREEN  "\033[1;32m"
#define _CLR_RESET  "\033[0m"
using i64 = long long;
using i128 = __int128;
inline std::ostream& operator<<(std::ostream& os, __int128 n) {
    if (n == 0) return os << "0";
    if (n < 0) { os << "-"; n = -n; }
    std::string s;
    while (n > 0) { s += (char)('0' + (n % 10)); n /= 10; }
    std::reverse(s.begin(), s.end());
    return os << s;
}

template <typename T>
void dbg_out(const T& val) { std::cerr << val; }

template <typename A, typename B>
void dbg_out(const std::pair<A, B>& p) { std::cerr << '(' << p.first << ", " << p.second << ')'; }

template <typename T>
requires requires(T t) { t.begin(); t.end(); }
void dbg_out(const T& v) {
    std::cerr << '[';
    bool first = true;
    for (const auto& x : v) {
        if (!first) std::cerr << ",";
        first = false;
        dbg_out(x);
    }
    std::cerr << ']';
    std::cerr << "Total:" << v.size() << '\n';
}
template <typename T, std::size_t N>
void dbg_out(const T (&a)[N]) {
    std::cerr << '[';
    for (std::size_t i = 0; i < N; ++i) {
        if (i > 0) std::cerr << ",";
        dbg_out(a[i]);
    }
    std::cerr << "]";
    std::cerr << "Total:" << N << '\n';
}
template <typename T>
requires requires(T t) { t.begin(); t.end(); }
void dbg_out_range(const T& v, int L, int R) {
    std::cerr << '[';
    bool first = true;
    auto it = std::next(v.begin(), L);
    for (int i = L; i < R && it != v.end(); ++i, ++it) {
        if (!first) std::cerr << ",";
        first = false;
        dbg_out(*it);
    }
    std::cerr << "]";
    std::cerr << "Range: [" << L << ", " << R << "), Total: " << v.size() << '\n';
}
template <typename T, std::size_t N>
void dbg_out_range(const T (&a)[N], int L, int R) {
    std::cerr << '[';
    for (int i = L; i < R && i < (int)N; ++i) {
        if (i > L) std::cerr << ",";
        dbg_out(a[i]);
    }
    std::cerr << "]";
    std::cerr << "Range: [" << L << ", " << R << "), Total: " << N << "\n";
}
#define debug(x) \
    std::cerr << _CLR_CYAN << "[" << #x << "]" << _CLR_RESET << '\n'; \
    std::cerr << _CLR_GREEN; dbg_out(x); std::cerr << _CLR_RESET << '\n';

#define debug_range(x, L, R) \
    std::cerr << _CLR_CYAN << "[" << #x << "]" << _CLR_RESET << '\n'; \
    std::cerr << _CLR_GREEN; dbg_out_range(x, L, R); std::cerr << _CLR_RESET << '\n';

```



- int 与 int 相乘 会溢出， 应该转为i64



### 字符串的stl操作

```c++
string text;
text.find(word, pos) // ==> string::npos;
text.replace(pos, len, str)

    // 输入
    std::cin // 会留下一个换行符
    getline(cin, s); // 读取， 直到换行符， 会吃掉换行符
	std::cin.ignore(); // 吃掉一个字符
	// 标准流程(读取多行字符串)是
	std::cin >> n;
	std::cin.ignore();
	for (...) {
		std::getline(std::cin, s);
    }
```

### sort的元素满足传递性

- **P2123** 中我们可以通过sgn(x) 来比较 $min(a_1,b_2) 与 min(a_2, b_1)$, 
