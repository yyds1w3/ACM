#include <iostream>
#include <vector>
using namespace std;
const int N = 5e6 + 1;
int a[N], n, k;
void qselect(int l, int r, int k){
    if (l >= r) return;
    int x = a[(l + r) / 2]; // pivot
    int i = l, j = r;
    while (i <= j){
        while(a[i] < x) i++; 
        while(a[j] > x) j--; 
        if (i <= j){
            swap(a[i], a[j]); // 将违规的值交换
            i++, j--;
        }
    }
    if (k <= j) qselect(l, j, k); // 递归左边
    else if (k >= i) qselect(i, r, k); // 递归右边
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    qselect(0, n - 1, k);
    cout << a[k];
}