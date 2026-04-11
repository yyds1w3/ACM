#!/bin/bash

SESSION="ACM"
WORK_DIR="$PWD"
ACM_ROOT="$HOME/ACM"         
LIB_DIR="$ACM_ROOT/lib"       # Lib 文件夹路径

# =========================================

tmux has-session -t $SESSION 2>/dev/null
if [ $? != 0 ]; then
  tmux new-session -d -s $SESSION -n "Code" -c "$WORK_DIR" -x "$(tput cols)" -y "$(tput lines)"
  tmux split-window -h -p 33 -t $SESSION:Code -c "$WORK_DIR"
  tmux split-window -v -t $SESSION:Code.2 -c "$WORK_DIR"

  tmux new-window -t $SESSION -n "Lib" -c "$LIB_DIR"
  tmux send-keys -t $SESSION:Lib "nvim ." Enter
  
  tmux select-window -t $SESSION:Code
  tmux select-pane -t $SESSION:Code.1
fi
tmux attach -t $SESSION

