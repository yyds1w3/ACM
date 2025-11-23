#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int i;
    while (k){
        for (i = 0; s[i] <= s[i+1];++i);
        s.erase(i, 1);
        k--;
    }
    while(s[0] == '0' && s.size() >= 1){
        s.erase(0,1);
    }
}