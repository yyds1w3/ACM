#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

// 如果是 Windows 系统，加上这个头文件用来控制颜色
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int WIDTH = 80;  // 屏幕宽度
const int HEIGHT = 30; // 屏幕高度
int len[WIDTH];        // 每一列雨滴的长度
int pos[WIDTH];        // 每一列雨滴当前的下落位置

// 设置控制台颜色为绿色 (Windows专用)
void setGreen() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#endif
}

int main() {
    srand(time(0)); // 随机数种子
    setGreen();     // 变绿！

    // 初始化每一列的起始位置
    for (int i = 0; i < WIDTH; ++i) {
        pos[i] = rand() % HEIGHT;
        len[i] = rand() % 15 + 5;
    }

    while (true) {
        string buffer = "";
        
        // 生成这一帧的画面
        for (int i = 0; i < WIDTH; ++i) {
            // 只有当雨滴在当前位置时才打印字符
            if (i % 2 == 0) { // 隔一列下一行，更有感觉
                 char c = (rand() % 2) ? '0' : '1'; // 010101
                 cout << c << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;

        // 让程序暂停 50 毫秒，控制下落速度
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    return 0;
}