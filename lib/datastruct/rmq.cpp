#include <bits/stdc++.h>

using i64 = long long;

template<class T, class Cmp = std::less<T>>
struct RMQ {
    int n;
    std::vector<std::vector<T>> st;
    Cmp cmp;

    RMQ() {} // 为全局变量
    RMQ(const std::vector<T>& a) { // 单个测试用例
        init(a);
    }
    void init(const std::vector<T>& a) { // 多个测试用例手动init
        n = a.size();
        if (n == 0) return;
        int logn = std::__lg(n) + 1;
        st.assign(logn, std::vector<T>(n));
        for (int i = 0; i < n; ++i) {
            st[0][i] = a[i];
        }
        for (int j = 1; j < logn; ++j) {
            for (int i = 0; i + (1 << (j)) <= n; ++i) {
                st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))], cmp);
            }
        }
    }
    // 左闭右开[l, r)
    T operator()(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        int k = std::__lg(r - l);
        return std::min(st[k][l], st[k][r - (1 << k)], cmp);
    }
};
