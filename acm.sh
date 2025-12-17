#!/bin/bash

# ================= 配置区 =================
SESSION="ACM"
WORK_DIR="$PWD"       
DUIPAI_DIR="$HOME/ACM/duipai" 
# =========================================

tmux has-session -t $SESSION 2>/dev/null
if [ $? != 0 ]; then
  
  # ==========================================
  # Window 1: Code 
  # ==========================================
  
  # 【关键修复 1】: 加上 -x 和 -y 参数
  # $(tput cols) 和 $(tput lines) 会获取你当前终端的真实宽高
  # 这样后台创建的会话尺寸就是正确的，百分比计算才不会错
  tmux new-session -d -s $SESSION -n "Code" -c "$WORK_DIR" -x "$(tput cols)" -y "$(tput lines)"

  # 1. 左右切分 (黄金三角布局第一刀)
  # 【关键修复 2】: 直接使用 -p 25
  # 意思是：切出来的右边那个窗格(Pane 2)占 25%
  # 那么左边的代码区(Pane 1)自然就占 75% 了
  # 这比先切分再 resize-pane 要稳定得多！
  tmux split-window -h -p 25 -t $SESSION:Code -c "$WORK_DIR"

  # 2. 右边上下切分
  # 对 Pane 2 (右边) 进行切分
  tmux split-window -v -t $SESSION:Code.2 -c "$WORK_DIR"


  # ==========================================
  # Window 2: Duipai
  # ==========================================
  
  tmux new-window -t $SESSION -n "Duipai" -c "$WORK_DIR"

  # 左右切分
  tmux split-window -h -t $SESSION:Duipai -c "$WORK_DIR"
  
  # 打开文件 (适配 1-based index)
  tmux send-keys -t $SESSION:Duipai.1 "nvim $DUIPAI_DIR/gen.cpp" Enter
  tmux send-keys -t $SESSION:Duipai.2 "nvim $DUIPAI_DIR/std.cpp" Enter

  # ==========================================
  # 收尾
  # ==========================================
  
  tmux select-window -t $SESSION:Code
  tmux select-pane -t $SESSION:Code.1

fi

tmux attach -t $SESSION
