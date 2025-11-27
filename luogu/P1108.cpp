#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    long long a, b;
}a[100002];

bool cmp(Item x, Item y)
{
    return x.b * y.a < y.b * x.a;
}

int main()
{
    int n;
    long long p;
    cin >> n >> p;
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].a >> a[i].b;
        sum += a[i].a;
    }
    if (sum <= p){
        cout << -1;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    a[n + 1].a = 0, a[n + 1].b = 100000;
    //额外设备，使用时间无限
    for (int i = 2; i <= n + 1; i++){
        if (a[i - 1].b * a[i].a + a[i].b * p < a[i].b * a[i - 1].a){
            printf("%.6lf", 1.00 * a[i - 1].b / (a[i - 1].a - p));
            return 0;
        }
        a[i].a += a[i-1].a;
        a[i].b += a[i-1].b;
    }
    return 0;
}   