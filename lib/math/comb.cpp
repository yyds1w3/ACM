#include <bits/stdc++.h>
#include "Z.cpp"
struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invFac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invFac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invFac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; ++i) {
            _fac[i] = _fac[i - 1] * i; 
        }
        _invFac[m] = _fac[m].inv();
        for (int i = m; i > n; --i) {
            _invFac[i - 1] = _invFac[i] * i;
            _inv[i] = _invFac[i] * _fac[i - 1];
        }
        n = m; 
    }
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invFac(int m) {
        if (m > n) init(2 * m);
        return _invFac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z cnm(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invFac(m) * invFac(n - m);
    }
};
