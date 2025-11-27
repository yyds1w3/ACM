#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a, b, c;

void f(double l, double r){
    double m = (l + r) / 2;
    if (r - l < 1e-4) {
        cout << setprecision(1) << fixed << m * 100;
        return;
    }
    double tmp = a;
    for (int i = 0; i < c; ++i){
        tmp = tmp * (1+m) - b;
    }
    if (tmp > 0) f(l,m); // 利息多了
    else if (tmp < 0)f(m,r); // 利息少了
    else {
        cout << setprecision(1) << fixed << m * 100;
        return;
    }
}

int main() {
    cin >> a >> b >> c;
    f(0,5);

}
