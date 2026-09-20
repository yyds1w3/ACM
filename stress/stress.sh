#!/bin/bash
# ============================================================
# 对拍：gen 造数据 → sol 和 brute 各跑一遍 → 比输出
#
# 用法：  ./stress.sh [轮数] [san]
#           ./stress.sh            默认 1000 轮
#           ./stress.sh 1000 san   顺带开 asan+ubsan 抓越界/溢出
#
# 依赖：  当前目录下有 sol.cpp / brute.cpp / gen.cpp
# ============================================================
set -u
N=${1:-1000}
if [ "${2:-}" = "san" ]; then
    SAN="-fsanitize=address,undefined -g"
    echo "(已开启 sanitizer：能直接抓出越界和溢出)"
else
    SAN=""
fi

for f in sol brute gen; do
    g++ -O2 $SAN -o "$f" "$f.cpp" || { echo "$f.cpp 编译失败"; exit 1; }
done

for ((i = 1; i <= N; i++)); do
    ./gen > in.txt
    ./sol   < in.txt > o1.txt
    ./brute < in.txt > o2.txt

    # 把连续空白压成一个空格再比，免得行尾空格/换行差异造成假反例
    if ! diff -q <(tr -s ' \n' ' ' < o1.txt) <(tr -s ' \n' ' ' < o2.txt) > /dev/null; then
        echo "========== 第 $i 轮抓到反例 =========="
        echo "--- in.txt ---"; cat in.txt
        echo "--- 你的输出 ---"; cat o1.txt
        echo "--- 暴力输出 ---"; cat o2.txt
        exit 1
    fi
    if [ $((i % 100)) -eq 0 ]; then echo "  ... $i 轮"; fi
done

echo "跑了 $N 轮，没有抓到反例"
