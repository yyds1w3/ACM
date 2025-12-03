#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int N = 1e4 + 5;
const int P = 131;
string s;
vector<ull> v;
int n;
ull get_hash(string s){
    ull h = 0;
    for (char c : s){
        h = h * P + c;
    }
    return h;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        v.push_back(get_hash(s));
    }
    sort(v.begin(), v.end());
    cout << unique(v.begin(), v.end()) - v.begin();
}
