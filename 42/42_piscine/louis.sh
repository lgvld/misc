alias ..="cd .."
alias ...="cd ../.."
# alias c=cd
alias code="/Applications/Visual\ Studio\ Code.app/Contents/Resources/app/bin/code"
alias g=git
alias ga="git add"
alias gc="git commit"
alias gcl="git clone"
alias gp="git push"
alias gst="git status"
alias l=ls
alias m=mkdir
alias s="source ~/42_piscine/louis.sh"
alias v=vim
alias mr="make re"

mkcdir()
{
	mkdir -p -- "$1" &&
	cd -P -- "$1"
}

alias mc=mkcdir

alias c="gcc -Wall -Wextra -Werror"
# alias ccc="gcc ~/42_piscine/main.c ~/42_piscine/c*/ex*/*.c -o ~/42_piscine/a.out && ~/42_piscine/a.out"
alias ccc="gcc ~/42_piscine/main.c ~/42_piscine/c05/ex*/*.c -o ~/42_piscine/a.out && ~/42_piscine/a.out | cat -e"
# alias n="norminette -R CheckForbiddenSourceHeader"
alias n="norminette"
# alias normichette="norminette -R CheckForbiddenSourceHeader"
alias normichette="norminette"

gacp()
{
	git add . &&
	git commit -m "lazy commit" &&
	git push
}
