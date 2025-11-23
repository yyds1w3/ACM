#include <iostream>
using namespace std;
const int N = 1e6+5;
int F[N];
int main(){
    int n;
    cin >> n;
    F[1] = 1;
    F[2] = 2;
    F[3] = 5;
    for (int i = 4; i <= n; ++i){
        F[i] = (2 * F[i-1]) + F[i-3];
        F[i] %= 10000;
    }
    cout << F[n];
}