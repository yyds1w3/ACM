## Liner Basic
- P3812 by p[64] to express the xor sum situation of many numbers

## Div under mod
0 === 0%
1 === 100%
inv(2) === 50% === qpow(2, p-2)
inv(3) === 33% === qpow(3, p-2)

## 筛法

### 调和级数筛

- P2926

> xxxxxxxxxx s.substr(pos, len);s.find(sub);stoi(s); stoll(s);to_string(value);​cpp

```cpp
	 for (int i = 1; i <= max_v; ++i){
        if (cnt[i] == 0) continue;
        for (int j = i; j <= max_v; j += i){
            ans[j] += cnt[i];
        }
    }
// i 是小因子
// j 是 2i .. 3i .. 4i ....
```



### 欧拉筛

> 在$O(N)$的时间内求解积性函数
>
> 积性函数: 如果ab互质$f(ab) = f(a) \times f(b)$

```cpp
void euler_sieve(int n){
    int cnt = 0;
    not_prime[0] = not_prime[1] = 0;
    for (int i = 2; i * i <= n; ++i){
        if (not_prime[i]) primes[cnt++] = i;
        for (int p : primes){
            if (1LL * i * p > n) break;
            not_prime[i * p] = true;
            if (i % p == 0) break;
        }
    }
}
```



### 埃式筛

>在$O(NloglogN)$用于筛选素数

```cpp
void eratosthenes_sieve(int n) {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j <= n; j += i) {
                not_prime[j] = true;
            }
        }
    }
}
```

### 区间筛

- P1835

### 整除分块

- P1403
- 可以用来处理$\sum_i^n\lfloor\frac{n}{i}\rfloor$

```cpp
for (int l = 1, r; l <= n; l = r + 1){
	r = n / (n / l); // 这一块的值
    ans += (n / l) * (r - l + 1); // 这一块的值 * 
}
```

### 因子和

#### 求$a^b$的因子和[P1593](https://www.luogu.com.cn/problem/P1593)

1. 求a的因子和

   2. a的所有因子都是a的质因子的倍数 例子: 24 = 2 * 2 * 2 * 3(1, 2, 3, 4, 6, 8, 12, 24) == (1 + 2 + 4 + 8 + 3 + 6 + 12 + 24) == 60
   3. $O(\sqrt{n})$求出a的质因子$p_1...p_n$
   4. 前半部分是(1 + 2 + 4 + 8) 后半部分是 ( 3 + 6 + 12 + 24)
   5. 因子和为(1 + 2 + 4 + 8) * ( 1 + 3) == (1 + 3 + 2 + 6 + 3 + 12 + 8 + 24) 
   6. 所以我们的目标是求$a = p_1^{c_1}...p_n^{c_n}$
   7. $ans = \sum_{i=0}^{c_1}{p_1^i}$ 

2. 求$a^b$的因子和

   $a^b = p_1^{c_1*b}.....$

```cpp
    for (int i = 2; i * i <= a; ++i){
        if (a % i == 0){
            ll cnt = 0; // 求出原数包含了多少个同样的质因子 (1, 2, 4, 8)则cnt为3， 由2^3
            while (a % i == 0){
                cnt++;
                a /= i;
            }
            ans = (ans * sum_geometric(i, cnt * b)) % MOD; // ans *= (1 + 2 + 4 + 8),， 这里有b所以是(1+2+4+..+2^3b )
        }
    }
```

3. 如果a是一个很大的质数, 比如9901， 他的约数是1和9901， 9901是他的最小质因数， 是不是我们i要循环到n而非$\sqrt{n}$? ， 但是由于一个数、最多存在一个大于$\sqrt{n}$的约数， 所以我们只需要判断最后的a> 1吗就可以了（a> 1代表还剩下最后一个**质数**没有被之前的数分解）
```cpp
       if (a > 1){
           ans = ans * sum_geometric(a, b) % MOD;
       }
```





