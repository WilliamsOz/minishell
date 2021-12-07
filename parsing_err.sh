#!/bin/sh


# Parsing Errors :
# cc\cc
# Unsuported character found
# cc;cc
# Unsuported character found
# <
# bash: syntax error near unexpected token `newline'
# <<
# bash: syntax error near unexpected token `newline'
# >
# bash: syntax error near unexpected token `newline'
# >>
# bash: syntax error near unexpected token `newline'
# |
# bash: syntax error near unexpected token `|'
# ||
# bash: syntax error near unexpected token `||'
# < || >
# bash: syntax error near unexpected token `||'



# Okay :
# cc'\'cc
# cc';'cc