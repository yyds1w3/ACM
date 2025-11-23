#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct st {
    int t, v;
} p[1000000];

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    int limit = a + b;

    string ss;
    getline(cin, ss); // 清掉上一行残留的 '\n'

    int i = 0;
    for (int k = 0; k < n; k++) {
        getline(cin, ss);
        stringstream sss(ss);

        int t, v;
        sss >> t >> v;

        if (t <= limit) { 
            p[i].t = t;
            p[i].v = v;
            i++;
        }
    }

    sort(p, p + i, [](const st &m, const st &n){
        return m.v < n.v;
    });

    int ans = 0;
    for (int j = 0; j < i; j++) {
        if (s >= p[j].v) {
            s -= p[j].v;
            ans++;
        } else break;
    }

    cout << ans;
}
