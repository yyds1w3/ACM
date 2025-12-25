#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define BIT_METHOD 1
#define MS_METHOD 0
#if BIT_METHOD
const int N = 5e5 + 5;
int n;
int tree[N], a[N], b[N];
int lowbit(int x){
    return x &(-x);
}
void add(int x, int k){
    while (x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}
int ask(int x){
    int ans = 0;
    while (x){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - b - 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int id = lower_bound(b + 1, b + 1 + len, a[i]) - b; // 当前的a[i]是第几大的
        add(id, 1); // tree[id] += 1
        ans += i - ask(id); // i 总共插入的数量, ask(id) <= id的数量
    }
    cout << ans;
}
#endif
#if MS_METHOD
#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int a[N];     // 原数组
int temp[N];  // 临时数组 (归并排序必须)
long long ans = 0; // 记录逆序对数量

// [L, R] 是当前处理的区间
void merge_sort(int L, int R) {
    // 1. 递归边界：只有一个数，不用排
    if (L >= R) return;

    // 2. 分：切成两半
    int mid = (L + R) >> 1; // 相当于 (L+R)/2
    merge_sort(L, mid);     // 排左边
    merge_sort(mid + 1, R); // 排右边

    // 3. 治：合并两个有序数组
    int i = L;        // 左半边指针
    int j = mid + 1;  // 右半边指针
    int k = 0;        // 临时数组指针

    while (i <= mid && j <= R) {
        if (a[i] <= a[j]) {
            // 左边小，正常情况，没逆序对
            temp[k++] = a[i++];
        } else {
            // 右边小 (a[j] < a[i])
            // 【关键】统计逆序对
            // 左边从 i 到 mid 的所有数都比 a[j] 大
            ans += (mid - i + 1);
            
            temp[k++] = a[j++];
        }
    }

    // 4. 扫尾：把剩下一半没放完的直接抄过来
    while (i <= mid) temp[k++] = a[i++];
    while (j <= R) temp[k++] = a[j++];

    // 5. 搬运：把排好序的 temp 倒回原数组 a
    for (int p = 0; p < k; p++) {
        a[L + p] = temp[p];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    merge_sort(1, n);

    cout << ans << endl;
    return 0;
}
#endif
