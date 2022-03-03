#!/bin/bash

SESSION_NAME="code"

tmux has-session -t $SESSION_NAME &> /dev/null

if [ $? != 0 ]
then
	tmux new-session -s $SESSION_NAME -n editor -d
	tmux send-keys 'nvim .'
	tmux new-window -n build
	tmux send-keys 'cd build && clear'
	tmux new-window -n general
fi

tmux attach -t $SESSION_NAME
