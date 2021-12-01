#!/bin/sh
# This script will test minishell project
echo "cat -e -a -d file"
echo "cat -e $LESS -a -d file"
echo '''c'a''t' ''-'e'' '''$LESS''' '-a -d' file''
echo 'cat -e '$LESS' -a -d file'
echo cat -e ""$LESS"E"
echo cat -e ""$"LE"SS"E"