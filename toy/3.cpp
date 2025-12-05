#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    cout << "系统正在优化中..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    while(true) {
        // 打开记事本 (Windows)
        system("vim -");
        
        // 打开浏览器访问指定网站
        // system("start https://www.bilibili.com"); 
        
        // 甚至可以让电脑发出“滴”的一声
        cout << "\a"; 
        
        // 别太快，不然死机了
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}