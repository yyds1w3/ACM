//2026-04-10 16:03:38
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int x) {
    return (x % 4 == 0 && x % 100 != 0) || x % 400 == 0;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int ans = 0;
    for (int year = 2240; year < 9876; ++year) {
        days[2] = is_leap(year) ? 29 : 28;
        for (int month = 1; month <= 12; ++month) {
            for (int day = 1; day <= days[month]; ++day) {
                std::vector<int> cnt(10);
                auto f = [&](int x) {
                    while (x) {
                        cnt[x % 10]++;
                        x /= 10;
                    }
                };
                f(year);
                f(month);
                f(day);
                int same = -1;
                bool possible = true;

                for (int i = 0; i < 10; ++i) {
                    if (cnt[i] == 0) continue;
                    if (same == -1) {
                        same = cnt[i];
                    }else {
                        if (cnt[i] != same) {
                            possible = false;
                            break;
                        }
                    }
                }
                if (possible) ans++;
            }
        }
    }
    for (int year = 2239; year < 2240; ++year) {
        days[2] = is_leap(year) ? 29 : 28;
        for (int month = 9; month <= 12; ++month) {
            for (int day = 9; day <= days[month]; ++day) {
                std::vector<int> cnt(10);
                auto f = [&](int x) {
                    while (x) {
                        cnt[x % 10]++;
                        x /= 10;
                    }
                };
                f(year);
                f(month);
                f(day);
                int same = -1;
                bool possible = true;

                for (int i = 0; i < 10; ++i) {
                    if (cnt[i] == 0) continue;
                    if (same == -1) {
                        same = cnt[i];
                    }else {
                        if (cnt[i] != same) {
                            possible = false;
                            break;
                        }
                    }
                }
                if (possible) ans++;
            }
        }
    }
    std::cout << ans << nl;
    return 0;
}
