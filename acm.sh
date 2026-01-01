#!/bin/bash

# ================= 配置区 =================
SESSION="ACM"
WORK_DIR="$PWD"
ACM_ROOT="$HOME/ACM"          
DUIPAI_DIR="$ACM_ROOT/duipai"
LIB_DIR="$ACM_ROOT/lib"       # Lib 文件夹路径
MD_DIR="$ACM_ROOT/md"         # MD 文件夹路径
# =========================================

tmux has-session -t $SESSION 2>/dev/null
if [ $? != 0 ]; then
  
  # ==========================================
  # Window 1: Code 
  # ==========================================
  tmux new-session -d -s $SESSION -n "Code" -c "$WORK_DIR" -x "$(tput cols)" -y "$(tput lines)"
  tmux split-window -h -p 25 -t $SESSION:Code -c "$WORK_DIR"
  tmux split-window -v -t $SESSION:Code.2 -c "$WORK_DIR"

  # ==========================================
  # Window 2: Duipai
  # ==========================================
  tmux new-window -t $SESSION -n "Duipai" -c "$WORK_DIR"
  tmux split-window -h -t $SESSION:Duipai -c "$WORK_DIR"
  tmux send-keys -t $SESSION:Duipai.1 "nvim $DUIPAI_DIR/gen.cpp" Enter
  tmux send-keys -t $SESSION:Duipai.2 "nvim $DUIPAI_DIR/std.cpp" Enter

  # ==========================================
  # Window 3: Lib (模板库) -> nvim 文件树
  # ==========================================
  # 1. 创建窗口，并把工作目录设为 LIB_DIR
  tmux new-window -t $SESSION -n "Lib" -c "$LIB_DIR"
  # 2. 发送 "nvim ." 命令，这会直接在 nvim 里打开文件树
  tmux send-keys -t $SESSION:Lib "nvim ." Enter

  # ==========================================
  # Window 4: Note (笔记) -> nvim 文件树
  # ==========================================
  # 1. 创建窗口，并把工作目录设为 MD_DIR
  tmux new-window -t $SESSION -n "Note" -c "$MD_DIR"
  # 2. 同样发送 "nvim ."
  tmux send-keys -t $SESSION:Note "nvim ." Enter

  # ==========================================
  # 收尾
  # ==========================================
  tmux select-window -t $SESSION:Code
  tmux select-pane -t $SESSION:Code.1

fi

tmux attach -t $SESSION
