#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 power(i64 a, i64 b) {
    i64 res = 1;
    for (; b > 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}
int get_priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    vector<string> postfix;
    vector<char> ops;
    for (char c : s) {
        if (isdigit(c)) {
            postfix.push_back(string(1, c));
        } else if (c == '(') {
            ops.push_back(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.back() != '(') {
                postfix.push_back(string(1, ops.back()));
                ops.pop_back();
            }
            if (!ops.empty()) ops.pop_back();
        } else {
            while (!ops.empty() && ops.back() != '(') {
                if (c == '^' && ops.back() == '^') {
                    break;
                }
                if (get_priority(ops.back()) >= get_priority(c)) {
                    postfix.push_back(string(1, ops.back()));
                    ops.pop_back();
                } else {
                    break;
                }
            }
            ops.push_back(c);
        }
    }
    while (!ops.empty()) {
        postfix.push_back(string(1, ops.back()));
        ops.pop_back();
    }
    auto print_state = [&]() {
        for (int i = 0; i < (int)postfix.size(); i++) {
            cout << postfix[i] << " \n"[i == (int)postfix.size() - 1];
        }
    };
    print_state();
    while (postfix.size() > 1) {
        for (int i = 0; i < (int)postfix.size(); i++) {
            string token = postfix[i];
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                i64 a = stoll(postfix[i - 2]);
                i64 b = stoll(postfix[i - 1]);
                i64 res = 0;

                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") res = a / b;
                else if (token == "^") res = power(a, b);
                postfix[i - 2] = to_string(res);
                postfix.erase(postfix.begin() + i - 1, postfix.begin() + i + 1);
                break;
            }
        }
        print_state();
    }
    return 0;
}
