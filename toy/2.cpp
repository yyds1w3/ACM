#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    double x, y;
    
    // --- 颜色代码定义 ---
    // \033 是转义字符，[1;35m 代表亮粉色/洋红色，[0m 代表重置
    const string PINK = "\033[1;35m";
    const string RESET = "\033[0m";

    for (double t = 0; ; t += 0.1) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        double zoom = 1.2 + 0.2 * sin(t); 

        for (y = 1.3; y >= -1.1; y -= 0.1 / zoom) {
            for (x = -1.2; x <= 1.2; x += 0.05 / zoom) {
                double a = x * x + y * y - 1;
                
                if (a * a * a - x * x * y * y * y <= 0.0) {
                    // 这里加入颜色变量
                    cout << PINK << "*"; 
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        
        // 文字也可以加颜色
        cout << RESET << "\n For "<< PINK << "Ling" << RESET << " in 2017 & " << PINK << "You" << RESET << " in 2025" << endl;
        
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}