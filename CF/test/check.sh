#!/bin/bash

# 1. 检查参数
if [ $# -ne 3 ]; then
    echo -e "\033[31m[Error]\033[0m 参数错误！"
    echo "用法: ./check.sh <我的代码> <暴力/标程> <生成器>"
    exit 1
fi

MY_PROG=$1
STD_PROG=$2
GEN_PROG=$3

# 配置：是否删除 AC (正确) 的文件？
# true  = 省空间模式 (推荐)，AC后立即删除文件，只保留 WA 的那个
# false = 历史模式，保留所有生成过的 in 和 out 文件 (注意磁盘空间!)
CLEAN_AC_FILES=false  

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

mkdir -p prog in out

# 2. 编译阶段
echo -e "${YELLOW}Compiling...${NC}"
g++ "${MY_PROG}.cpp" -o "./prog/$MY_PROG" -O2 || exit 1
g++ "${STD_PROG}.cpp" -o "./prog/$STD_PROG" -O2 || exit 1
g++ "${GEN_PROG}.cpp" -o "./prog/$GEN_PROG" || exit 1

echo -e "${GREEN}Compilation Successful! Start Testing...${NC}"
echo "------------------------------------------------"

# 3. 对拍循环
for ((i=1; i<=100; i++)); do
    # 【核心修改】使用变量 i 来构造文件名
    IN_FILE="./in/data_${i}.in"
    MY_OUT="./out/my_${i}.out"
    STD_OUT="./out/std_${i}.out"

    # 生成数据
    ./prog/"$GEN_PROG" > "$IN_FILE"
    
    # 运行程序
    ./prog/"$MY_PROG" < "$IN_FILE" > "$MY_OUT"
    ./prog/"$STD_PROG" < "$IN_FILE" > "$STD_OUT"
    
    # 比较差异
    if diff -w "$MY_OUT" "$STD_OUT" > /dev/null; then
        printf "Test Case %-5d: ${GREEN}AC${NC}\r" "$i"
        
        # 【清理逻辑】如果是 AC，且开启了清理模式，则删除这组文件
        if [ "$CLEAN_AC_FILES" = true ]; then
            rm "$IN_FILE" "$MY_OUT" "$STD_OUT"
        fi
    else
        echo "" 
        echo "------------------------------------------------"
        echo -e "Test Case $i: ${RED}WA (Wrong Answer)!${NC}"
        echo -e "Files saved as: ${YELLOW}data_${i}.in${NC}, ${YELLOW}my_${i}.out${NC}, ${YELLOW}std_${i}.out${NC}"
        echo "------------------------------------------------"
        
        echo -e "${YELLOW}[Input Preview]:${NC}"
        head -n 10 "$IN_FILE" # 只显示前10行，防止数据太长刷屏
        echo "..."
        echo "------------------------------------------------"
        
        # 出错后退出循环，此时第 i 组文件会被保留下来
        break
    fi
done

echo ""