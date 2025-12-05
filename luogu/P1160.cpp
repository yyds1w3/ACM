#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int L[N], R[N];
bool exist[N];
int main(){
    int n, m;
    cin >> n;
    R[0] = 1;
    exist[1] = true;
    for (int i = 2; i <= n; ++i){
        int k, p;
        cin >> k >> p;
        exist[i] = true;
        if (p == 1){
            R[i] = R[k];
            L[i] = k;
            L[R[k]] = i;
            R[k] = i;
            exist[i] = true;
        }else if(p == 0){
            L[i] = L[k];
            R[i] = k;
            R[L[k]] = i;
            L[k] = i;
            exist[i] = true;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        if (exist[x]){
            exist[x] = false;
            R[L[x]] = R[x];
            L[R[x]] = L[x];
        }
    }
    int curr = R[0];
    while (curr != 0){
        cout << curr << " ";
        curr = R[curr];
    }
}