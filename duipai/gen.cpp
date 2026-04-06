#include <bits/stdc++.h>

#define nl '\n'
using i64 = long long;
using i128 = __int128;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// [l, r]
i64 Int(i64 l, i64 r) {
    return std::uniform_int_distribution<i64>(l, r)(rng);
}
std::vector<int> Permutaion(int n, int start) {
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), start);
    std::shuffle(p.begin(), p.end(), rng);
    return p;
}
std::string String(int len) {
    std::string s;
    while (s.size() < len) {
        char c = Int(0, 127) % 128; 
        if (!std::isspace(c)) {
            s += c;
        }
    }
    return s;
}
int main() {

}
