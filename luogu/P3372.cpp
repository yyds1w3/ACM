#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll tree[N << 2];
ll lazy[N << 2]; // 打上懒标记意味着该节点已经修改, 但是子节点没有, 懒标记只能下放
ll a[N]; 
int n,m,x,y,op;
ll k;
// 左孩子, 右孩子
inline int ls(int p) {return p << 1;}
inline int rs(int p) {return (p << 1) | 1;}
// push_up是把子节点的tree加到父节点
void push_up(int p){
    tree[p] = tree[ls(p)] + tree[rs(p)];
}
// push_down下放懒标记, 使用时一定不是叶子节点
void push_down(int p, int len){
    if (lazy[p]){
        // left
        lazy[ls(p)] += lazy[p];
        tree[ls(p)] += lazy[p] * (len - (len >> 1));
        // right
        lazy[rs(p)] += lazy[p];
        tree[rs(p)] += lazy[p] * (len >> 1);
        // p
        lazy[p] = 0;
    }
}
// p代表本节点, l, r代表管辖a[l ~ r]
void build(int p, int l, int r){
    if (l == r){
        tree[p] = a[l];
        return;
    }
    // 假设l = 1, r = 4, mid = 2
    int mid = (l + r) >> 1;
    build(ls(p), l, mid); // 1~2
    build(rs(p), mid + 1, r); // 3~4
    push_up(p); // 回溯更新父节点
}
// 区间修改[nl, nr] + k
void update(int p, int l, int r, int nl, int nr, ll k){
    if (nl <= l && r <= nr){
        tree[p] += k * (r - l + 1);
        lazy[p] += k;
        return;
    }
    // 没有完全覆盖
    push_down(p, r-l+1); // 下放懒标记
    int mid = (l + r) >> 1; 
    if (nl <= mid) update(ls(p), l, mid, nl, nr, k);
    if (nr >  mid) update(rs(p), mid+1, r, nl, nr, k);
    push_up(p); // 回溯更新父节点
}
ll query(int p, int l, int r, int nl, int nr){
    if (nl <= l && r <= nr) return tree[p];
    push_down(p, r-l+1);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (nl <= mid) res += query(ls(p), l, mid, nl, nr);
    if (nr > mid) res += query(rs(p), mid+1, r, nl, nr);
    // 没有push_up, 因为没有修改, 上方的数据是最新的且不用动
    return res;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i){
        cin >> op;
        if (op == 1){
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }else if (op == 2){
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
}
