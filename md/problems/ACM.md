## 动态规划

### 线性DP



### 最长递增子序列

```cpp
tails数组 --> tails[1] = 7 代表长度为2的LIS的最小结尾数字为7
```





### 树上DP

> 套路： 父节点的**全集信息**需要靠子节点的**全集信息**递归来返回

- 例题

  - 树上背包
    - [1](https://www.luogu.com.cn/problem/P12136)
    - [2](https://www.luogu.com.cn/problem/P1273)

  - 树上DP
    - [1](https://www.luogu.com.cn/problem/P1352)
    - [2](https://www.luogu.com.cn/problem/P1122)


### 数位DP



## 数据结构



### BIT

维护可差分信息（由两个大区间得到一个小区间）

1. 单点修改 + 区间查询（维护原数组） **P3374**

2. 单点查询 + 区间修改（维护差分数组）**P3368**
3. 二维数组 + 单点修改 + 区间查询 （维护二维数组）

### DSU



## 算法

### 字符串

#### 马拉车

> 解决回文问题



#### KMP

#### 字符串哈希



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
