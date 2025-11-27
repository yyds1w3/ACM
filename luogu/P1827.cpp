#include <iostream>
using namespace std;

string pre, inorder;
void f(string pre, string inorder){
    if (pre.empty()) return;
    char root = pre[0];
    int k = inorder.find(root);
    pre.erase(pre.begin());
    string leftpre = pre.substr(0, k);
    string rightpre = pre.substr(k);
    string leftinorder = inorder.substr(0, k);
    string rightinorder = inorder.substr(k+1);
    f(leftpre, leftinorder); // 左子树的f
    f(rightpre, rightinorder); // 右子树的f
    putchar(root); // 打印本节点
}

int main(){
    cin >> inorder >> pre;
    f(pre, inorder);
    return 0;
}