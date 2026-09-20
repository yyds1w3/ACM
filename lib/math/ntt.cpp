#include <bits/stdc++.h>
using i64 = long long;
// 把两个数组相乘求多项式子系数
// v[0] = v[0]*x^0, v[1] = v[1]*x^1...;
const int MOD = 998244353;
const int G = 3;          // 998244353 的原根
const int GI = 332748118; // G 在模 998244353 下的乘法逆元 (即 3 的倒数)
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
i64 inv(i64 x) {
    return qpow(x, MOD - 2);
}
std::vector<int> rev;
void ntt(std::vector<i64>& A, int type) {
    int limit = A.size();
    for (int i = 0; i < limit; ++i) {
        if (i < rev[i]) std::swap(A[i], A[rev[i]]);
    }
    for (int mid = 1; mid < limit; mid <<= 1) {
        i64 Wn = qpow(type == 1 ? G : GI, (MOD - 1) / (mid << 1));
        for (int j = 0; j < limit; j += (mid << 1)) {
            i64 w = 1;
            for (int k = 0; k < mid; ++k) {
                i64 x = A[j + k];
                i64 y = w * A[j + k + mid] % MOD;
                A[j + k] = (x + y) % MOD;
                A[j + k + mid] = (x - y + MOD) % MOD;
                w = w * Wn % MOD;
            }
        }
    }
    if (type == -1) {
        i64 inv_limit = inv(limit);
        for (int i = 0; i < limit; ++i) {
            A[i] = (A[i] * inv_limit) % MOD;
        }
    }
}
std::vector<i64> poly_multiply(std::vector<i64> A, std::vector<i64> B) {
    int n = A.size(), m = B.size();
    if (n == 0 || m == 0) return {};
    int target_len = n + m - 1;
    int limit = 1, L = 0;
    while (limit < target_len) {
        limit <<= 1;
        L++;
    }
    A.resize(limit, 0);
    B.resize(limit, 0);
    rev.assign(limit, 0);
    for (int i = 0; i < limit; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
    }
    ntt(A, 1);
    ntt(B, 1);
    for (int i = 0; i < limit; ++i) {
        A[i] = (A[i] * B[i]) % MOD;
    }
    ntt(A, -1);
    A.resize(target_len);
    return A;
}
