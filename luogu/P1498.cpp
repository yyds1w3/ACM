#include <iostream>
#include <cstring>
using namespace std;

char a[5000][5000]; // 足够大

// 在 (x, y) 作为顶点，画大小为 n 的图腾
void draw(int x, int y, int n) {
    if (n == 1) {
        // 基础图形，高 2，宽 4
        a[x][y] = '/';
        a[x][y+1] = '\\';
        a[x+1][y-1] = '/';
        a[x+1][y] = '_';
        a[x+1][y+1] = '_';
        a[x+1][y+2] = '\\';
        return;
    }
    int h = 1 << n; // 高度 = 2^n

    // 递归画三个子结构
    draw(x, y, n - 1);                     // 上
    draw(x + h/2, y - h/2, n - 1);         // 左下
    draw(x + h/2, y + h/2, n - 1);         // 右下
}

int main() {
    int n;
    cin >> n;

    int h = 1 << n;     // 高度
    int w = h << 1;     // 宽度 = 2*h

    // 初始化为空格
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            a[i][j] = ' ';

    // 顶点在 (0, w/2)
    draw(0, w/2, n);

    // 输出
    for (int i = 0; i < h; i++) {
        for (int j = 1; j <= w/2+i+1 ; j++)
            cout << a[i][j];
        cout << "\n";
    }
}
