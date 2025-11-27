#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTreeLazyRangeAdd
{
    vector<T> tree, lazy; // 线段树和懒标记
    vector<T> *arr;       // 叶子节点
    int n, root, n4, end;

    // 下传懒标记
    void maintain(int cl, int cr, int p)
    {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && lazy[p])
        { // 懒标记非空且有子树， 则下传懒标记，更新子节点
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            tree[p * 2] += lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] += lazy[p] * (cr - cm);
            lazy[p] = 0;
        }
    }
    // 区间和
    T range_sum(int l, int r, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
            return tree[p]; // 查询区间大于叶子节点区间
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p); // 下穿懒标记
        if (l <= m)
            sum += range_sum(l, r, cl, m, p * 2); // 左子树
        if (r > m)
            sum += range_sum(l, r, m + 1, cr, p * 2 + 1); // 右子树
        return sum;
    }

    void range_add(int l, int r, T val, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
        { // 查询区间大于叶子区间
            lazy[p] += val;
            tree[p] += (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m)
            range_add(l, r, val, cl, m, p * 2);
        if (r > m)
            range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void build(int s, int t, int p)
    {
        if (s == t)
        {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

public:
    explicit SegTreeLazyRangeAdd<T>(vector<T> v)
    {
        n = v.size();
        n4 = n * 4;
        tree = vector<T>(n4, 0);
        lazy = vector<T>(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr; // 不再需要叶子节点的数组了， 后面的操作不需要这个
    }

    void show(int p, int depth = 0)
    {
        if (p > n4 || tree[p] == 0)
            return;             // 空节点或者超界
        show(p * 2, depth + 1); // 左孩子
        for (int i = 0; i < depth; ++i)
            putchar('\t');
        printf("%d:%d\n", tree[p], lazy[p]); //
        show(p * 2 + 1, depth + 1);          // 右孩子
    }

    T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_add(int l, int r, T val) { range_add(l, r, val, 0, end, root); }
};


