#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int A[N];
int n, M, sum = 0;

bool judge(int x){
    int sum = 0, times = 1;
    for (int i = 1; i <= n; ++i){
        sum += A[i];
        if (sum > x){ // 有大于就加
            sum = A[i];
            times++;
        }
    }
    if (times <= M) return true;
    return false; 
}
int main(){
    cin >> n >> M;
    int l = A[1];
    for (int i = 1; i <= n; ++i){
        cin >> A[i];
        sum += A[i];
        l = max(l, A[i]);
    }
    l--;
    int r = sum;
    while (l < r - 1){ // 0 1 2
        int m = l + (r - l) / 2;
        if (judge(m) == true){ // 是否可以更大
            r = m;
        }else{
            l = m;
        }
    }
    cout << r;

}