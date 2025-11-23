#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int a[100000];
int main() {
    int n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int s = 0;
    for (int i = 1; i < n;++i){
        if (a[i] > a[i-1]){
            s += a[i] - a[i-1];
        }
    }
    s += a[1];
    cout << s;
}
